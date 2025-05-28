/** ExaTN::Numerics: Tensor network builder: PEPS: Projected Entangled Pair States
 *
 * Srikar: Just copied from MPS and replaced all MPS with PEPS to avoid conflicts.
REVISION: 2025/05/28

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
			bool appended = true;
			auto output_tensor = network.getTensor(0);
			auto output_tensor_rank = output_tensor->getRank();
			assert(output_tensor_rank > 0);
			const auto &output_dim_extents = output_tensor->getDimExtents();

			const int num_phys_legs = tensor_operator ? 2 : 1;

			// Create PEPS or PEPO tensors with 2D grid connectivity:
			for (long long i = 0; i < Lx_; ++i)
			{
				for (long long j = 0; j < Ly_; ++j)
				{
					long long tensor_id = 1 + i * Ly_ + j;
					std::vector<DimExtent> dims;

					// Virtual bond dimensions: left, top, right, bottom
					DimExtent left = (j > 0) ? max_bond_dim_ : 1;
					DimExtent top = (i > 0) ? max_bond_dim_ : 1;
					DimExtent right = (j < Ly_ - 1) ? max_bond_dim_ : 1;
					DimExtent bottom = (i < Lx_ - 1) ? max_bond_dim_ : 1;

					// Add virtual bond dims
					dims.push_back(left);
					dims.push_back(top);
					dims.push_back(right);
					dims.push_back(bottom);

					// Add physical leg(s)
					for (int p = 0; p < num_phys_legs; ++p)
						dims.push_back(output_dim_extents[tensor_id - 1 + p * Lx_ * Ly_]);

					// Tensor leg connections: will be set after all tensors are added
					std::vector<TensorLeg> legs;
					// Placeholder legs to satisfy API (will rewire after tensor placement)
					for (int k = 0; k < (4 + num_phys_legs); ++k)
						legs.emplace_back(0, 0);

					appended = network.placeTensor(tensor_id,
						std::make_shared<Tensor>("_T" + std::to_string(tensor_id), dims), legs, false, false);
					assert(appended);
					auto &tensor = *(network.getTensor(tensor_id));
					tensor.rename(generateTensorName(tensor, "t"));
				}
			}

			// Rewire leg connections between tensors (grid connectivity)
			for (long long i = 0; i < Lx_; ++i)
			{
				for (long long j = 0; j < Ly_; ++j)
				{
					long long tensor_id = 1 + i * Ly_ + j;
					auto conn = network.getTensorConn(tensor_id);
					int leg = 0;

					// LEFT
					if (j > 0)
						conn->resetLeg(leg++, TensorLeg(tensor_id - 1, 2));
					else
						conn->resetLeg(leg++, TensorLeg(0, tensor_id - 1)); // open to output

					// TOP
					if (i > 0)
						conn->resetLeg(leg++, TensorLeg(tensor_id - Ly_, 3));
					else
						conn->resetLeg(leg++, TensorLeg(0, tensor_id - 1));

					// RIGHT
					if (j < Ly_ - 1)
						conn->resetLeg(leg++, TensorLeg(tensor_id + 1, 0));
					else
						conn->resetLeg(leg++, TensorLeg(0, tensor_id - 1));

					// BOTTOM
					if (i < Lx_ - 1)
						conn->resetLeg(leg++, TensorLeg(tensor_id + Ly_, 1));
					else
						conn->resetLeg(leg++, TensorLeg(0, tensor_id - 1));

					// PHYSICAL LEG(S)
					for (int p = 0; p < num_phys_legs; ++p)
						conn->resetLeg(leg++, TensorLeg(0, tensor_id - 1 + p * Lx_ * Ly_));
				}
			}

			network.finalize();
			return;
		}

		std::unique_ptr<NetworkBuilder> NetworkBuilderPEPS::createNew()
		{
			return std::unique_ptr<NetworkBuilder>(new NetworkBuilderPEPS());
		}

	} // namespace numerics

} // namespace exatn
