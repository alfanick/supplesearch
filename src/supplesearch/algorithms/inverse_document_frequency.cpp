#include "inverse_document_frequency.hpp"

#include "bag_of_words.hpp"

#include <algorithm>
#include <cmath>

using namespace SuppleSearch::Algorithms;

InverseDocumentFrequency::InverseDocumentFrequency(const SuppleSearch::Database::shared database) :
  database_(database) {
}

arma::vec InverseDocumentFrequency::process(SuppleSearch::WordList keywords) {
  BagOfWords bow(keywords);

  arma::mat word_occurences = bow.process(database_);
  arma::vec result(keywords.size());

  size_t document_count = database_->documents().size();

  for (size_t i = 0; i < keywords.size(); i++) {
    double occurences = arma::accu(word_occurences.row(i) > 0);

    if (occurences > 0)
      result(i) = std::log(document_count / occurences);
  }

  return result;
}


