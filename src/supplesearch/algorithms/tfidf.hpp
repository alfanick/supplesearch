#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_

#include "term_frequency.hpp"

namespace SuppleSearch {
namespace Algorithms {

/**
 * TFIDF algorithm implementation
 */
class TFIDF {
  public:
    /**
     * Create instance of TFIDF working
     * on given keywords.
     *
     * @param keywords Keywords to process
     */
    TFIDF(SuppleSearch::WordList keywords);

    /**
     * Calculate TFIDF represenation
     * of given Database.
     *
     * @param database Database to process
     * @return TFIDF representation
     */
    arma::mat process(SuppleSearch::Database::shared database);

  private:
    //! Keywords to process
    SuppleSearch::WordList keywords_;
    //! TF algorithm
    TermFrequency term_frequency_;

};

}
}

#endif
