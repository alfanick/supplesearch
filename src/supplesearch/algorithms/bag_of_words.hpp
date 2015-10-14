#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_BAG_OF_WORDS_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_BAG_OF_WORDS_HPP_

#include "../database.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Algorithms {

/**
 * Counts number of occurences of given
 * keywords in the database
 */
class BagOfWords {
  public:
    /**
     * Create new BagOfWords algorithm with
     * given keywords.
     *
     * @param keywords Keywords
     */
    BagOfWords(SuppleSearch::WordList keywords);

    /**
     * Process single Document
     *
     * @param document Document to compare
     * @return Vector of occurences
     */
    arma::vec process(SuppleSearch::Document::shared document);

    /**
     * Process whole database
     *
     * @param database Database to compare
     * @return Matrix of occurences
     */
    arma::mat process(SuppleSearch::Database::shared database);

  private:
    //! Keywords
    SuppleSearch::WordList keywords_;
};

}
}

#endif
