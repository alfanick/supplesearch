#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_TERM_FREQUENCY_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_TERM_FREQUENCY_HPP_

#include "bag_of_words.hpp"

namespace SuppleSearch {
namespace Algorithms {

class TermFrequency {
  public:
    TermFrequency(const SuppleSearch::WordList keywords);

    arma::vec process(SuppleSearch::Document::shared document);
    arma::mat process(SuppleSearch::Database::shared database);

  private:
    BagOfWords bag_of_words_;
};

}
}

#endif
