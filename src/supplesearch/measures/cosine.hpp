#ifndef ALJ_SUPPLESEARCH_MEASURES_COSINE_HPP_
#define ALJ_SUPPLESEARCH_MEASURES_COSINE_HPP_

#include "../measure.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Measures {

class Cosine : public Measure {
  public:
    double compare(arma::vec a, arma::vec b) override;
    arma::vec compare(arma::mat documents, arma::vec query) override;
};

}
}

#endif
