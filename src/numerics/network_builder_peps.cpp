/** ExaTN::Numerics: Tensor network builder: PEPS: Projected Entangled Pair States
 * 
 * Srikar: Just copied from MPS and replaced all MPS with PEPS to avoid conflicts.
REVISION: 2023/05/23

Copyright (C) 2018-2021 Dmitry I. Lyakh (Liakh)
Copyright (C) 2018-2021 Oak Ridge National Laboratory (UT-Battelle) **/

#include "network_builder_peps.hpp"
#include "network_builder_mps.hpp"
#include "tensor_network.hpp"

#include <initializer_list>

namespace exatn{

namespace numerics{

NetworkBuilderPEPS::NetworkBuilderPEPS():
 max_bond_dim_(1), Lx_(2), Ly_(2)
{
}


bool NetworkBuilderPEPS::getParameter(const std::string & name, long long * value) const
{
 bool found = true;
 if(name == "max_bond_dim"){
  *value = max_bond_dim_;
 }else if(name == "Lx"){
  *value = Lx_;
 }else if(name == "Ly"){
  *value = Ly_;
 }else{
  found = false;
 }
 return found;
}


bool NetworkBuilderPEPS::setParameter(const std::string & name, long long value)
{
 bool found = true;
 if(name == "max_bond_dim"){
  max_bond_dim_ = value;
 }else if(name == "Lx"){
  Lx_ = value;
 }else if(name == "Ly"){
  Ly_ = value;
 }else{
  found = false;
 }
 return found;
}


void NetworkBuilderPEPS::build(TensorNetwork & network, bool tensor_operator)
{
 std::cout << "Srikar: Build for PEPS is called\n";
 bool appended = true;
 //Inspect the output tensor:
 auto output_tensor = network.getTensor(0);
 auto output_tensor_rank = output_tensor->getRank();
 assert(output_tensor_rank > 0);
 const auto & output_dim_extents = output_tensor->getDimExtents();
 for(int i = 0; i < output_tensor_rank; ++i){
	std::cout << output_dim_extents[i] << " ";
 }
 std::cout << "\n";
 // Layers that will later add up and form PEPS
 std::cout << "Lx_=" << Lx_ << " Ly_=" << Ly_ << std::endl;
 std::vector<std::shared_ptr<TensorNetwork> > layers(Lx_);
 // For Lx layers, first Ly dimensions belong to top layer, last Ly dimensions belong to bottom layer. In between, every MPO has Ly dimensions.
 std::vector<std::vector<DimExtent> > dims_in_layer;
 for(DimExtent i=0; i < Lx_; i++) {
	std::vector<DimExtent> each;
	for(DimExtent j=0; j < Ly_; j++){
		each.push_back((DimExtent)4);
	}
	dims_in_layer.push_back(each);
 }
 auto & network_build_factory = *(numerics::NetworkBuildFactory::get());
 // top layer MPS
 auto peps = network_build_factory.createNetworkBuilderShared("MPS");
 auto success = peps->setParameter("max_bond_dim", max_bond_dim_); assert(success);
 auto output_tensor_mps_top = makeSharedTensor("Z_MPS", dims_in_layer[0]);
 auto network_peps = makeSharedTensorNetwork("PEPS",output_tensor_mps_top, *peps);
 layers[0] = network_peps;
 // middle layer(s)
 for(DimExtent i=1; i <= Lx_-2; i++) {
	auto middle_mpo = network_build_factory.createNetworkBuilderShared("MPS");
	auto success = middle_mpo->setParameter("max_bond_dim", max_bond_dim_); assert(success);
	auto output_tensor_middle_mpo = makeSharedTensor("Z_MPS", dims_in_layer[i]);
	auto network_middle_mpo = makeSharedTensorNetwork("TensorTrain",output_tensor_middle_mpo, *middle_mpo);
	layers[i] = network_middle_mpo;
 }
 // bottom layer MPS
 auto bottom_mps = network_build_factory.createNetworkBuilderShared("MPS");
 success = bottom_mps->setParameter("max_bond_dim", max_bond_dim_); assert(success);
 auto output_tensor_mps_bottom = makeSharedTensor("Z_MPS", dims_in_layer[Lx_-1]);
 auto network_bottom_mps = makeSharedTensorNetwork("TensorTrain",output_tensor_mps_bottom, *bottom_mps);
 layers[Lx_-1] = network_bottom_mps;
 // TODO: join layers (1,..) to 0 form PEPS
 for(int i=1; i < Lx_; i++) {
	// connect layer i
	std::cout << "connecting layer " << i << std::endl;
	layers[i]->printIt();
	// don't know how to use paring yet. I'm manually doing pairing below later.
	bool success_append = network_peps->appendTensorNetwork(std::move(*layers[i]), {});
	assert(success_append);
 }
 // for each tensor in PEPS, modify TensorLeg if needed.
 for (int tensor_id = 1; tensor_id <= Lx_ * Ly_; ++tensor_id) {
	if (tensor_id == 1) {
		// Top-left corner
		std::cout << "TOP-LEFT - " << tensor_id << std::endl;
		// below and right legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id == Lx_) {
		// Top-right corner
		std::cout << "TOP-RIGHT - " << tensor_id << std::endl;
		// left and below legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id == (Ly_ - 1) * Lx_ + 1) {
		// Bottom-left corner
		std::cout << "BOTTOM-LEFT - " << tensor_id << std::endl;
		// up and right legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id == Lx_ * Ly_) {
		// Bottom-right corner
		std::cout << "BOTTOM-RIGHT - " << tensor_id << std::endl;
		// left and up legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id > 1 && tensor_id < Lx_) {
		// Top boundary cells
		std::cout << "TOP - " << tensor_id << std::endl;
		// left, right, down legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id > (Ly_ - 1) * Lx_ && tensor_id < Lx_ * Ly_) {
		// Bottom boundary cells
		std::cout << "BOTTOM - " << tensor_id << std::endl;
		// left, right and up legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if ((tensor_id - 1) % Lx_ == 0 && tensor_id != 1 && tensor_id != (Ly_ - 1) * Lx_ + 1) {
		// Left boundary cells
		std::cout << "LEFT - " << tensor_id << std::endl;
		// up, down, right legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else if (tensor_id % Lx_ == 0 && tensor_id != Lx_ && tensor_id != Lx_ * Ly_) {
		// Right boundary cells
		std::cout << "RIGHT - " << tensor_id << std::endl;
		// up, down, left legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
	else {
		// Middle cells
		std::cout << "MIDDLE - " << tensor_id << std::endl;
		// up, down, left and right legs
		network_peps->getTensor(tensor_id)->printIt();
		std::cout << "\n" << "adj list - ";
		std::list<unsigned int> l = network_peps->getAdjacentTensors(tensor_id);
		for (auto const& i : l) {
			std::cout << i << " ";
		}
		std::cout << "\n";
	}
 }
 network = *network_peps;
 return;
}


std::unique_ptr<NetworkBuilder> NetworkBuilderPEPS::createNew()
{
 return std::unique_ptr<NetworkBuilder>(new NetworkBuilderPEPS());
}

} //namespace numerics

} //namespace exatn
