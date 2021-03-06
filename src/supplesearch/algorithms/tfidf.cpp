#include "tfidf.hpp"

using namespace SuppleSearch::Algorithms;

void TFIDF::keywords(SuppleSearch::WordList kw) {
  keywords_ = kw;
  term_frequency_ = std::make_shared<Algorithms::TermFrequency>(kw);
}

arma::mat TFIDF::process(SuppleSearch::Database::shared database) {
  inverse_document_frequency_ = std::make_shared<Algorithms::InverseDocumentFrequency>(database);

  arma::mat tfidf = term_frequency_->process(database);
  arma::vec idf = inverse_document_frequency_->process(keywords_);

  for (size_t i = 0; i < tfidf.n_cols; i++) {
    tfidf.col(i) %= idf;
  }

  return tfidf;
}

arma::vec TFIDF::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  arma::vec idf = inverse_document_frequency_->process(keywords_);
  arma::vec tfidf = term_frequency_->process(document);

  return tfidf % idf;
}
