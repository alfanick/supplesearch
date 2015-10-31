#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_TERM_FREQUENCY_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_TERM_FREQUENCY_HPP_

#include "bag_of_words.hpp"

namespace SuppleSearch {
namespace Algorithms {

/**
 * Term Frequency algorithm - normalised
 * BagOfWords by max of occurences in given
 * Document
 */
class TermFrequency {
  public:
    typedef std::shared_ptr<TermFrequency> shared;

    /**
     * Create TermFrequency algorithm with
     * given keywords.
     *
     * @param keywords Keywords
     */
    TermFrequency(const SuppleSearch::WordList keywords);

    /**
     * Process single Document
     *
     * @param document Document to compare
     * @return Vector of weights
     */
    arma::vec process(SuppleSearch::Document::shared document);

    /**
     * Process whole database
     *
     * @param database Database to compare
     * @return Matrix of weights
     */
    arma::mat process(SuppleSearch::Database::shared database);

  private:
    //! Used BagOfWords algorithm
    BagOfWords bag_of_words_;
};

}
}

#endif
