#ifndef ALJ_SUPPLESEARCH_MEASURE_HPP_
#define ALJ_SUPPLESEARCH_MEASURE_HPP_

#include "database.hpp"
#include "document.hpp"

#include <armadillo>

namespace SuppleSearch {

class Measure {
  public:
    typedef std::shared_ptr<Measure> shared;

    virtual arma::vec compare(arma::mat document, arma::vec query) = 0;
};

}

#endif
