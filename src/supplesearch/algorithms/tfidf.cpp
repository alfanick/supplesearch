#include "tfidf.hpp"

#include "inverse_document_frequency.hpp"

using namespace SuppleSearch::Algorithms;

TFIDF::TFIDF(SuppleSearch::WordList keywords) :
  keywords_(keywords), term_frequency_(keywords) {
}

arma::mat TFIDF::process(SuppleSearch::Database::shared database) {
  InverseDocumentFrequency inverse_document_frequency_(database);

  arma::mat tfidf = term_frequency_.process(database);
  arma::vec idf = inverse_document_frequency_.process(keywords_);

  for (size_t i = 0; i < tfidf.n_cols; i++) {
    tfidf.col(i) %= idf;
  }

  return tfidf;
}
