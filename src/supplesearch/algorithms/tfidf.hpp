#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_

#include "term_frequency.hpp"

namespace SuppleSearch {
namespace Algorithms {

class TFIDF {
  public:
    TFIDF(SuppleSearch::WordList keywords);

    arma::mat process(SuppleSearch::Database::shared database);

  private:
    SuppleSearch::WordList keywords_;
    TermFrequency term_frequency_;

};

}
}

#endif
