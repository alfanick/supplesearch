#include "cosine.hpp"

#include <memory>

using namespace SuppleSearch::Measures;

void Cosine::keywords(WordList k) {
  Measure::keywords(k);

  tfidf_ = std::make_shared<SuppleSearch::Algorithms::TFIDF>(k);
}

void Cosine::query(SuppleSearch::Document::shared document) {
  query_tfidf_ = tfidf_->process(database_, document);
}

arma::vec Cosine::compare() {
  arma::mat all_tfidf = tfidf_->process(database_);
  arma::vec scores(all_tfidf.n_cols);

  for (size_t i = 0; i < all_tfidf.n_cols; i++) {
    scores(i) = arma::norm_dot(all_tfidf.col(i), query_tfidf_);
  }

  return scores;
}

double Cosine::compare(SuppleSearch::Document::shared document) {
  return arma::norm_dot(tfidf_->process(database_, document), query_tfidf_);
}
