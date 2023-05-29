/** ExaTN::Numerics: Tensor network builder: PEPS: Projected Entangled Pair States
 * 
 * Srikar: Just copied from MPS and replaced all MPS with PEPS to avoid conflicts.
REVISION: 2023/05/23

Copyright (C) 2018-2021 Dmitry I. Lyakh (Liakh)
Copyright (C) 2018-2021 Oak Ridge National Laboratory (UT-Battelle) **/

/** Rationale:
 (a) Builds a projected entangled pair state tensor network:
     Parameters:
     * max_bond_dim: Maximal internal bond dimension;

 (b) Tensor numeration (tensor network vector): example- 3x6 lattice

	1       2       3       4       5       6
    X ----- X ----- X ----- X ----- X ----- X
   /|      /|      /|      /|      /|      /|
	|	    |	    |	    |	    | 	    |
	7       8	    9      10      11      12
	X ----- X ----- X ----- X ----- X ----- X
   /|      /|      /|      /|      /|      /|
	|	    |	    |	    |	    | 	    |
   13       14	    15      16      17      18
    X ----- X ----- X ----- X ----- X ----- X
   /       /       /       /       /       /
 
 (c) Projected Entanlged Pair Operator (PEPO) will just have additional open legs at the boundaries, like so-

          |       |       |       |       |       |
          |       |       |       |       |       |
	      1       2       3       4       5       6
    ----- X ----- X ----- X ----- X ----- X ----- X -----
         /|      /|      /|      /|      /|      /|
	      |	      |	      |	      |	      | 	  |
	      7       8	      9      10      11      12
	----- X ----- X ----- X ----- X ----- X ----- X -----
         /|      /|      /|      /|      /|      /|
	      |	      |	      |	      |	      | 	  |
         13       14	  15      16      17      18
    ----- X ----- X ----- X ----- X ----- X ----- X -----
         /|      /|      /|      /|      /|      /|
		  |       |       |       |       |       |

**/

#ifndef EXATN_NUMERICS_NETWORK_BUILDER_PEPS_HPP_
#define EXATN_NUMERICS_NETWORK_BUILDER_PEPS_HPP_

#include "tensor_basic.hpp"
#include "network_builder.hpp"

#include <string>
#include <memory>

#include "errors.hpp"

namespace exatn{

namespace numerics{

class NetworkBuilderPEPS: public NetworkBuilder{

public:

 NetworkBuilderPEPS();
 NetworkBuilderPEPS(const NetworkBuilderPEPS &) = default;
 NetworkBuilderPEPS & operator=(const NetworkBuilderPEPS &) = default;
 NetworkBuilderPEPS(NetworkBuilderPEPS &&) noexcept = default;
 NetworkBuilderPEPS & operator=(NetworkBuilderPEPS &&) noexcept = default;
 virtual ~NetworkBuilderPEPS() = default;

 /** Retrieves a specific parameter of the tensor network builder. **/
 virtual bool getParameter(const std::string & name, long long * value) const override;

 /** Sets a specific parameter of the tensor network builder. **/
 virtual bool setParameter(const std::string & name, long long value) override;

 /** Builds a tensor network of a specific kind. On input, the tensor
     network must only contain the output tensor with dummy legs.
     If tensor_operator = TRUE, the tensor network operator will
     be built instead of the tensor network vector. In that case,
     the first half legs correspond to ket while the rest to bra. **/
 virtual void build(TensorNetwork & network,                //inout: tensor network
                    bool tensor_operator = false) override; //in: tensor network vector or operator

 static std::unique_ptr<NetworkBuilder> createNew();

private:

 long long max_bond_dim_; 	//maximal internal bond dimension
 long long int Lx_; 		// number of horizontal lines in the lattice of PEPS
 long long int Ly_; 		// number of vertical lines in the lattice of PEPS

};

} //namespace numerics

} //namespace exatn

#endif //EXATN_NUMERICS_NETWORK_BUILDER_PEPS_HPP_
