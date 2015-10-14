#include "cosine.hpp"

using namespace SuppleSearch::Measures;

void Cosine::keywords(WordList k) {
  Measure::keywords(k);

  tfidf_ = tfidf_.make_shared(k);
}

void Cosine::query(SuppleSearch::Document::shared document) {
  query_tfidf_ = tfidf_->process(database_, document);
}

double Cosine::compare(SuppleSearch::Document::shared document) {
  return arma::norm_dot(tfidf_->process(database_, document), query_tfidf_);
}
