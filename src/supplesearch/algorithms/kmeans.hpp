#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_KMEANS_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_KMEANS_HPP_

#include <memory>
#include <armadillo>

#include "../database.hpp"
#include "../measure.hpp"

namespace SuppleSearch {
namespace Algorithms {

class KMeans {
  public:
    //! Shared pointer
    typedef std::shared_ptr<KMeans> shared;

    KMeans(Measure::shared measure, size_t k, size_t max_iterations);

    arma::vec process(arma::mat documents);

  protected:
    size_t k_;
    size_t max_iterations_;
    Measure::shared measure_;

};

}
}

#endif
