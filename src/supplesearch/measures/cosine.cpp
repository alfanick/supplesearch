#include "cosine.hpp"

#include <memory>

using namespace SuppleSearch::Measures;

arma::vec Cosine::compare(arma::mat database, arma::vec query) {
  arma::vec scores(database.n_cols);

  for (size_t i = 0; i < database.n_cols; i++) {
    scores(i) = arma::norm_dot(database.col(i), query);
  }

  return scores;
}
