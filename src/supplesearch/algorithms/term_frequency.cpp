#include "term_frequency.hpp"

using namespace SuppleSearch::Algorithms;

TermFrequency::TermFrequency(SuppleSearch::Database::shared keywords) :
  bag_of_words_(keywords) {
}

arma::vec TermFrequency::process(SuppleSearch::Document::shared document) {
  auto result = bag_of_words_.process(document);
  result /= result.max();

  return result;
}

arma::mat TermFrequency::process(SuppleSearch::Database::shared database) {
  arma::mat result;
  size_t index = 0;

  for (auto& document : database->documents()) {
    result.insert_cols(index++, process(document));
  }

  return result;
}
