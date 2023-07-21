#ifndef EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_PEPS_HPP_
#define EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_PEPS_HPP_

#include "contraction_seq_optimizer.hpp"

#include "errors.hpp"

namespace exatn{

namespace numerics{

class ContractionSeqOptimizerPEPS: public ContractionSeqOptimizer{

public:

 virtual double determineContractionSequence(TensorNetwork & network,
                                             std::list<ContrTriple> & contr_seq,
                                             std::function<unsigned int ()> intermediate_num_generator) override;

 static std::unique_ptr<ContractionSeqOptimizer> createNew();
};

} //namespace numerics

} //namespace exatn

#endif //EXATN_NUMERICS_CONTRACTION_SEQ_OPTIMIZER_PEPS_HPP_
