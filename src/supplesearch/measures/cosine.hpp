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
    void query(Document::shared q) override;
    arma::vec compare() override;
    double compare(Document::shared d) override;

  private:
    Algorithms::TFIDF::shared tfidf_;
    arma::vec query_tfidf_;
};

}
}

#endif
