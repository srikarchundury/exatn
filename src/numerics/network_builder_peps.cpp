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

namespace exatn
{

	namespace numerics
	{

		NetworkBuilderPEPS::NetworkBuilderPEPS() : max_bond_dim_(4), Lx_(1), Ly_(1)
		{
		}

		bool NetworkBuilderPEPS::getParameter(const std::string &name, long long *value) const
		{
			bool found = true;
			if (name == "max_bond_dim")
			{
				*value = max_bond_dim_;
			}
			else if (name == "Lx")
			{
				*value = Lx_;
			}
			else if (name == "Ly")
			{
				*value = Ly_;
			}
			else
			{
				found = false;
			}
			return found;
		}

		bool NetworkBuilderPEPS::setParameter(const std::string &name, long long value)
		{
			bool found = true;
			if (name == "max_bond_dim")
			{
				max_bond_dim_ = value;
			}
			else if (name == "Lx")
			{
				Lx_ = value;
			}
			else if (name == "Ly")
			{
				Ly_ = value;
			}
			else
			{
				found = false;
			}
			return found;
		}

		void NetworkBuilderPEPS::build(TensorNetwork &network, bool tensor_operator)
		{
			std::cout << "EXATN: Build for PEPS is called\n";
			// network.printIt();std::cout << std::endl;
			bool appended = true;
			// Inspect the output tensor:
			auto output_tensor = network.getTensor(0);
			auto output_tensor_rank = output_tensor->getRank();
			std::cout << "EXATN: output_tensor_rank " << output_tensor_rank << std::endl;
			assert(output_tensor_rank > 0);
			const auto &output_dim_extents = output_tensor->getDimExtents();
			std::cout << "EXATN: output_dim_extents - " << std::endl;
			for (int i = 0; i < output_tensor_rank; ++i)
			{
				std::cout << output_dim_extents[i] << " ";
			}
			std::cout << "\n";
			// Layers that will later add up and form PEPS
			std::cout << "EXATN: peps size "
					  << "Lx_=" << Lx_ << " Ly_=" << Ly_ << std::endl;
			// std::vector<std::shared_ptr<TensorNetwork>> layers(Lx_);
			// // Divide output_dim_extents into different MPS layers
			// // For Lx layers, first Ly dimensions of ouput_dim_extents belong to top layer, last Ly dimensions belong to bottom layer. In between, every MPO has Ly dimensions.
			// std::vector<std::vector<DimExtent>> dims_in_layer;
			// for (DimExtent i = 0; i < Lx_; i++)
			// {
			// 	std::vector<DimExtent> each;
			// 	// #pragma omp parallel for
			// 	for (DimExtent j = 0; j < Ly_; j++)
			// 	{
			// 		std::cout << "i=" << i << " j=" << j << " output_dim_extents[i * Lx_ + j] = " << output_dim_extents[i * Lx_ + j] << std::endl;
			// 		each.push_back(output_dim_extents[i * Lx_ + j]);
			// 	}
			// 	dims_in_layer.push_back(each);
			// }
			// std::cout << "EXATN: printing dims in each layer" << std::endl;
			// for (DimExtent i = 0; i < Lx_; i++)
			// {
			// 	std::cout << "EXATN: in layer " << i << " - ";
			// 	for (DimExtent j = 0; j < Ly_; j++)
			// 	{
			// 		std::cout << dims_in_layer[i][j] << " ";
			// 	}
			// 	std::cout << std::endl;
			// }
			// auto &network_build_factory = *(numerics::NetworkBuildFactory::get());
			// std::cout << "EXATN: more than 2 tensors" << std::endl;
			// // top layer MPS
			// std::cout << "EXATN: in top layer" << std::endl;
			// auto peps = network_build_factory.createNetworkBuilderShared("MPS");
			// auto success = peps->setParameter("max_bond_dim", max_bond_dim_);
			// assert(success);
			// auto output_tensor_mps_top = makeSharedTensor("Z_MPS", dims_in_layer[0]);
			// auto network_peps = makeSharedTensorNetwork("PEPS", output_tensor_mps_top, *peps);
			// layers[0] = network_peps;
			// // middle layer(s)
			// if (Lx_ >= 3)
			// {
			// 	std::cout << "EXATN: in middle layers" << std::endl;
			// 	for (DimExtent i = 1; i <= Lx_ - 2; i++)
			// 	{
			// 		auto middle_mpo = network_build_factory.createNetworkBuilderShared("MPS");
			// 		auto success = middle_mpo->setParameter("max_bond_dim", max_bond_dim_);
			// 		assert(success);
			// 		auto output_tensor_middle_mpo = makeSharedTensor("Z_MPS", dims_in_layer[i]);
			// 		auto network_middle_mpo = makeSharedTensorNetwork("TensorTrain", output_tensor_middle_mpo, *middle_mpo);
			// 		layers[i] = network_middle_mpo;
			// 	}
			// }
			// if (Lx_ >= 2)
			// {
			// 	// bottom layer MPS
			// 	std::cout << "EXATN: in bottom layer" << std::endl;
			// 	auto bottom_mps = network_build_factory.createNetworkBuilderShared("MPS");
			// 	success = bottom_mps->setParameter("max_bond_dim", max_bond_dim_);
			// 	assert(success);
			// 	auto output_tensor_mps_bottom = makeSharedTensor("Z_MPS", dims_in_layer[Lx_ - 1]);
			// 	auto network_bottom_mps = makeSharedTensorNetwork("TensorTrain", output_tensor_mps_bottom, *bottom_mps);
			// 	layers[Lx_ - 1] = network_bottom_mps;
			// }
			// if (Lx_ > 1)
			// {
			// 	std::cout << "EXATN: connecting all layers" << std::endl;
			// 	for (int i = 1; i < Lx_; i++)
			// 	{
			// 		// connect layer i
			// 		// std::cout << "connecting layer " << i << std::endl;
			// 		// layers[i]->printIt();
			// 		// don't know how to use paring yet, I'm manually doing pairing below later.
			// 		bool success_append = network_peps->appendTensorNetwork(std::move(*layers[i]), {});
			// 		assert(success_append);
			// 	}
			// This section can be removed once I figure out how `pairing` works.
			// for each tensor in PEPS, modify TensorLeg if needed.
			//  std::cout << "removing output legs." << std::endl;
			//  int leg_num = 0;
			//  while((network_peps->getTensorConn(0)->getTensorLegs()).size() != 0) {
			// 	std::cout << "deleting leg_num = " << leg_num << std::endl;
			// 	network_peps->getTensorConn(0)->deleteLeg(leg_num);
			// 	leg_num++;
			//  }
			// std::cout << "EXATN: computing internal bond dims (highly doubt this)" << std::endl;
			// // Compute internal bond dimensions:
			// DimExtent left_bonds[output_tensor_rank], right_bonds[output_tensor_rank], top_bonds[output_tensor_rank], bottom_bonds[output_tensor_rank];
			// DimExtent left_dim = 1;
			// for (int i = 0; i < output_tensor_rank; ++i)
			// {
			// 	left_bonds[i] = left_dim;
			// 	left_dim *= output_dim_extents[i];
			// 	if (left_dim > max_bond_dim_)
			// 		left_dim = max_bond_dim_;
			// }
			// DimExtent right_dim = 1;
			// for (int i = (output_tensor_rank - 1); i >= 0; --i)
			// {
			// 	right_bonds[i] = right_dim;
			// 	right_dim *= output_dim_extents[i];
			// 	if (right_dim > max_bond_dim_)
			// 		right_dim = max_bond_dim_;
			// }
			// DimExtent top_dim = 1;
			// for (int i = (output_tensor_rank - 1); i >= 0; --i)
			// {
			// 	top_bonds[i] = top_dim;
			// 	top_dim *= output_dim_extents[i];
			// 	if (top_dim > max_bond_dim_)
			// 		top_dim = max_bond_dim_;
			// }
			// DimExtent bottom_dim = 1;
			// for (int i = (output_tensor_rank - 1); i >= 0; --i)
			// {
			// 	bottom_bonds[i] = bottom_dim;
			// 	bottom_dim *= output_dim_extents[i];
			// 	if (bottom_dim > max_bond_dim_)
			// 		bottom_dim = max_bond_dim_;
			// }
			// left_dim = 1; top_dim = 1; right_dim = 1; bottom_dim = 1;
			std::cout << "EXATN: creating dummy tensor to be treated as null" << std::endl;
			appended = network.placeTensor(Lx_ * Ly_ + 1,												  // tensor id
										   std::make_shared<Tensor>("_T" + std::to_string(Lx_ * Ly_ + 1), // tensor name
																	std::initializer_list<DimExtent>{2,1,1,1,1,1}),
										   {TensorLeg{}, TensorLeg{}, TensorLeg{}, TensorLeg{}, TensorLeg{}, TensorLeg{}},
										   false,
										   false);
			assert(appended);
			auto &tensor = *(network.getTensor(Lx_ * Ly_ + 1));
			tensor.rename(generateTensorName(tensor, "dummy"));
			std::cout << "EXATN: placing tensors in PEPS" << std::endl;
			if(Lx_ == 1) {
				for (unsigned int tensor_id = 1; tensor_id <= Lx_ * Ly_; ++tensor_id)
				{
					if (tensor_id == 1) {
						std::cout << "LEFT-CORNER - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,	// tensor id
								std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
								std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
								{TensorLeg{0, tensor_id - 1}, TensorLeg{Lx_ * Ly_ + 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
								false,
								false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id == Lx_ * Ly_) {
						std::cout << "RIGHT-CORNER - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,	// tensor id
								std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
								std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
								{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{Lx_ * Ly_ + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
								false,
								false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else {
						std::cout << "OTHERS-IN-MIDDLE - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,	// tensor id
								std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
								std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
								{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
								false,
								false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
				}
			}
			else {
				for (unsigned int tensor_id = 1; tensor_id <= Lx_ * Ly_; ++tensor_id)
				{
					if (tensor_id == 1)
					{
						// Top-left corner
						std::cout << "TOP-LEFT - " << tensor_id << std::endl;
						// network_peps->getTensor(tensor_id)->printIt();
						// std::cout << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{Lx_ * Ly_ + 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id == Ly_)
					{
						// Top-right corner
						std::cout << "TOP-RIGHT - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{Lx_ * Ly_ + 1, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id == (Lx_ - 1) * Ly_ + 1)
					{
						// Bottom-left corner
						std::cout << "BOTTOM-LEFT - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{Lx_ * Ly_ + 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id == Ly_ * Lx_)
					{
						// Bottom-right corner
						std::cout << "BOTTOM-RIGHT - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{Lx_ * Ly_ + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id > 1 && tensor_id < Ly_)
					{
						// Top boundary cells
						std::cout << "TOP - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{Lx_ * Ly_ + 1, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id > (Lx_ - 1) * Lx_ && tensor_id < Ly_ * Lx_)
					{
						// Bottom boundary cells
						std::cout << "BOTTOM - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{Lx_ * Ly_ + 1, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if ((tensor_id - 1) % Ly_ == 0 && tensor_id != 1 && tensor_id != (Lx_ - 1) * Ly_ + 1)
					{
						// Left boundary cells
						std::cout << "LEFT - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{Lx_ * Ly_ + 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{tensor_id + Ly_, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else if (tensor_id % Ly_ == 0 && tensor_id != Ly_ && tensor_id != Ly_ * Lx_)
					{
						// Right boundary cells
						std::cout << "RIGHT - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{Lx_ * Ly_ + 1, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
					else
					{
						// Middle cells
						std::cout << "MIDDLE - " << tensor_id << std::endl;
						appended = network.placeTensor(tensor_id,												  // tensor id
													std::make_shared<Tensor>("_T" + std::to_string(tensor_id), // tensor name
																				std::initializer_list<DimExtent>{output_dim_extents[tensor_id - 1], 1, 1, 1, 1, 1}),
													{TensorLeg{0, tensor_id - 1}, TensorLeg{tensor_id - 1, 3}, TensorLeg{tensor_id - Ly_, 4}, TensorLeg{tensor_id + 1, 1}, TensorLeg{tensor_id + Ly_, 2}, TensorLeg{Lx_ * Ly_ + 1, 5}},
													false,
													false);
						assert(appended);
						auto &tensor = *(network.getTensor(tensor_id));
						tensor.rename(generateTensorName(tensor, "t"));
					}
				}
			}
			// std::cout << "EXATN: modifying 0 output tensor: " << std::endl;
			// 	for (auto const &i : network.getTensorConn(0)->getTensorLegs())
			// 	{
			// 		i.printIt();
			// 		network.getTensorConn(0)->deleteLeg(0);
			// 		std::cout << std::endl;
			// 	}
			// if (tensor_operator)
			// {
			// 	std::cout << "EXATN: tensor operator is True" << std::endl;
			// 	for (unsigned long int tensor_id = 1; tensor_id <= Lx_ * Ly_; ++tensor_id)
			// 	{
			// 		auto *tens_conn = network.getTensorConn(tensor_id);
			// 		tens_conn->appendLeg(output_dim_extents[output_tensor_rank + tensor_id - 1], TensorLeg{0, output_tensor_rank + tensor_id - 1});
			// 	}
			// }
			// auto *tens_conn = network.getTensorConn(0);
			// tens_conn->appendLeg(output_dim_extents[0], TensorLeg{0,0});
			std::cout << "EXATN: Running Finalize" << std::endl;
			network.finalize();
			// network = *network_peps;
			std::cout << "EXATN: PEPS generated is as follows: " << std::endl;
			for (unsigned long int tensor_id = 0; tensor_id <= Lx_ * Ly_ + 1; tensor_id++)
			{
				std::cout << "Tensor ID=" << tensor_id << std::endl;
				network.getTensor(tensor_id)->printIt(); std::cout << std::endl;
				for (auto const &i : network.getTensorConn(tensor_id)->getTensorLegs())
				{
					i.printIt();
					std::cout << std::endl;
				}
			}
			std::cout << "EXATN: End of build call" << std::endl;
			return;
		}

		std::unique_ptr<NetworkBuilder> NetworkBuilderPEPS::createNew()
		{
			return std::unique_ptr<NetworkBuilder>(new NetworkBuilderPEPS());
		}

	} // namespace numerics

} // namespace exatn
