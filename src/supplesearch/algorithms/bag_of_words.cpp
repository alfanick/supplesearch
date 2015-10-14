#include "bag_of_words.hpp"

#include <algorithm>

using namespace SuppleSearch::Algorithms;

BagOfWords::BagOfWords(SuppleSearch::Database::shared keywords) : keywords_database_(keywords) {
  for (auto& document : keywords->documents()) {
    auto stemmed = document->stemmed_content();
    keywords_.insert(keywords_.end(), stemmed.begin(), stemmed.end());
  }

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
