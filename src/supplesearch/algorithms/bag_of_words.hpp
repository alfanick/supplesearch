#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_BAG_OF_WORDS_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_BAG_OF_WORDS_HPP_

#include "../database.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Algorithms {

class BagOfWords {
  public:
    BagOfWords(SuppleSearch::Database::shared keywords);

    arma::vec process(SuppleSearch::Document::shared document);
    arma::mat process(SuppleSearch::Database::shared database);

  private:
    SuppleSearch::WordList keywords_;
    SuppleSearch::Database::shared keywords_database_;
};

}
}

#endif
