#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_INVERSE_DOCUMENT_FREQUENCY_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_INVERSE_DOCUMENT_FREQUENCY_HPP_

#include "../database.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Algorithms {

/**
 * Computes InverseDocumentFrequency represenation
 * of given vector.
 */
class InverseDocumentFrequency {
  public:
    /**
     * Create new InverseDocumentFrequency algorithm
     * on given Database.
     *
     * @param database Database to work with
     */
    InverseDocumentFrequency(const SuppleSearch::Database::shared database);

    /**
     * Calculate IDF for given keywords.
     *
     * @param keywods Keywords to process
     * @return IDF vector
     */
    arma::vec process(SuppleSearch::WordList keywords);

  private:
    //! Used database
    SuppleSearch::Database::shared database_;
};

}
}

#endif
