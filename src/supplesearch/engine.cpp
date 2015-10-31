#include "engine.hpp"

#include <algorithm>
#include <set>
#include <memory>

using namespace SuppleSearch;

Engine::Engine(const Database::shared database, const Database::shared keywords, const Measure::shared measure) :
  measure_(measure),
  database_(database) {
  std::set<std::string> s;

  for (auto document : keywords->documents()) {
    auto stemmed = document->stemmed_content();
    s.insert(stemmed.begin(), stemmed.end());
  }

  keywords_.insert(keywords_.end(), s.begin(), s.end());

  tfidf_ = std::make_shared<Algorithms::TFIDF>(keywords_);
  database_tfidf_ = tfidf_->process(database_);
}

ResultList Engine::query(const Document::shared q) {
  ResultList result;

  auto query_tfidf = tfidf_->process(database_, q);
  auto scores = measure_->compare(database_tfidf_, query_tfidf);

  int i = 0;
  for (const auto& document : database_->documents()) {
    result.push_back(std::make_pair(scores(i++), document));
  }

  std::sort(result.rbegin(), result.rend());

  return result;
}

ResultList Engine::query(const std::string q) {
  return query(database_->build_document("query", q));
}
