#include "cosine.hpp"

#include <memory>

using namespace SuppleSearch::Measures;

double Cosine::compare(arma::vec a, arma::vec b) {
  return arma::norm_dot(a, b);
}

arma::vec Cosine::compare(arma::mat database, arma::vec query) {
  arma::vec scores(database.n_cols);

  for (size_t i = 0; i < database.n_cols; i++) {
    scores(i) = compare((arma::vec)database.col(i), query);
  }

  return scores;
}
