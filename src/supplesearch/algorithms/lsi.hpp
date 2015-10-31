#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_LSI_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_LSI_HPP_

#include "tfidf.hpp"

namespace SuppleSearch {
namespace Algorithms {

class LSI : public TFIDF {
  public:
    //! Shared pointer
    typedef std::shared_ptr<LSI> shared;

    LSI(size_t degree);

    virtual arma::mat process(SuppleSearch::Database::shared database) override;

    virtual arma::vec process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) override;

  protected:
    size_t degree_;
};

}
}

#endif
