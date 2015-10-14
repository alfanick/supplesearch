#include "engine.hpp"

#include <algorithm>
#include <set>

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

  measure_->keywords(keywords_);
  measure_->database(database_);
}

ResultList Engine::query(const Document::shared q) {
  ResultList result;

  measure_->query(q);

  for (auto document : database_->documents()) {
    result.push_back(std::make_pair(measure_->compare(document), document));
  }

  std::sort(result.rbegin(), result.rend());

  return result;
}

ResultList Engine::query(const std::string q) {
  return query(database_->build_document("query", q));
}
