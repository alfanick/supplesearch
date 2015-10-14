#include "bag_of_words.hpp"

#include <algorithm>

using namespace SuppleSearch::Algorithms;

BagOfWords::BagOfWords(SuppleSearch::WordList keywords) : keywords_(keywords) {
}

arma::vec BagOfWords::process(SuppleSearch::Document::shared document) {
  arma::vec result(keywords_.size());
  size_t index = 0;
  auto stemmed = document->stemmed_content();

  for (auto keyword : keywords_) {
    result(index++) = std::count(stemmed.begin(), stemmed.end(), keyword);
  }

  return result;
}

arma::mat BagOfWords::process(SuppleSearch::Database::shared database) {
  arma::mat result;
  size_t index = 0;

  for (auto& document : database->documents()) {
    result.insert_cols(index++, process(document));
  }

  return result;
}
