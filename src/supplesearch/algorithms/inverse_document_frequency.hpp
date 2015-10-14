#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_INVERSE_DOCUMENT_FREQUENCY_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_INVERSE_DOCUMENT_FREQUENCY_HPP_

#include "../database.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Algorithms {

class InverseDocumentFrequency {
  public:
    InverseDocumentFrequency(const SuppleSearch::Database::shared database);

    arma::vec process(SuppleSearch::WordList keywords);

  private:
    SuppleSearch::Database::shared database_;
};

}
}

#endif
