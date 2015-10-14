#include "tfidf.hpp"

#include "inverse_document_frequency.hpp"

using namespace SuppleSearch::Algorithms;

TFIDF::TFIDF(SuppleSearch::WordList keywords) :
  keywords_(keywords), term_frequency_(keywords) {
}

arma::mat TFIDF::process(SuppleSearch::Database::shared database) {
  InverseDocumentFrequency inverse_document_frequency(database);

  arma::mat tfidf = term_frequency_.process(database);
  arma::vec idf = inverse_document_frequency.process(keywords_);

  for (size_t i = 0; i < tfidf.n_cols; i++) {
    tfidf.col(i) %= idf;
  }

  return tfidf;
}

arma::vec TFIDF::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  InverseDocumentFrequency inverse_document_frequency(database);

  arma::vec idf = inverse_document_frequency.process(keywords_);
  arma::vec tfidf = term_frequency_.process(document);

  return tfidf % idf;
}
