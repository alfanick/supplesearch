#ifndef ALJ_SUPPLESEARCH_MEASURES_COSINE_HPP_
#define ALJ_SUPPLESEARCH_MEASURES_COSINE_HPP_

#include "../measure.hpp"
#include "../algorithms/tfidf.hpp"

#include <armadillo>

namespace SuppleSearch {
namespace Measures {

class Cosine : public Measure {
  public:
    void keywords(WordList k) override;
    arma::vec compare(SuppleSearch::Document::shared query) override;

  private:
    Algorithms::TFIDF::shared tfidf_;
};

}
}

#endif
