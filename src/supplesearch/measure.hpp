#ifndef ALJ_SUPPLESEARCH_MEASURE_HPP_
#define ALJ_SUPPLESEARCH_MEASURE_HPP_

#include "database.hpp"
#include "document.hpp"

#include <armadillo>

namespace SuppleSearch {

class Measure {
  public:
    typedef std::shared_ptr<Measure> shared;

    virtual void keywords(WordList k) { keywords_ = k; }
    void database(Database::shared database) { database_ = database; }

    virtual void query(Document::shared q) = 0;
    virtual arma::vec compare() = 0;
    virtual double compare(Document::shared d) = 0;

  protected:
    WordList keywords_;
    Database::shared database_;
};

}

#endif
