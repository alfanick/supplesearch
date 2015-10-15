#include "cosine.hpp"

#include <memory>

using namespace SuppleSearch::Measures;

void Cosine::keywords(WordList k) {
  Measure::keywords(k);

  tfidf_ = std::make_shared<SuppleSearch::Algorithms::TFIDF>(k);
}

arma::vec Cosine::compare(SuppleSearch::Document::shared query) {
  arma::mat all_tfidf = tfidf_->process(database_);
  arma::vec query_tfidf = tfidf_->process(database_, query);
  arma::vec scores(all_tfidf.n_cols);

  for (size_t i = 0; i < all_tfidf.n_cols; i++) {
    scores(i) = arma::norm_dot(all_tfidf.col(i), query_tfidf);
  }

  return scores;
}
