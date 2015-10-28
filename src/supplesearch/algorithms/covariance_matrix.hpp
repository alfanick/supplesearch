#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_COVARIANCE_MATRIX_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_COVARIANCE_MATRIX_HPP_

#include "term_frequency.hpp"
#include "../engine.hpp"

#include <set>

namespace SuppleSearch {
namespace Algorithms {

class CovarianceMatrix {
  public:
    typedef std::shared_ptr<CovarianceMatrix> shared;

    CovarianceMatrix(SuppleSearch::Database::shared database, SuppleSearch::Database::shared keywords);

    SuppleSearch::ResultList process(SuppleSearch::Document::shared query, size_t, size_t);

  private:
    SuppleSearch::WordList keywords(SuppleSearch::Document::shared query);
    const std::string unstem(std::string term);
    std::vector<std::set<size_t>> find_best(const arma::vec possible, std::set<size_t> vis, size_t extra_keywords);

    SuppleSearch::Database::shared database_;
    SuppleSearch::Database::shared keywords_;
};

}
}

#endif
