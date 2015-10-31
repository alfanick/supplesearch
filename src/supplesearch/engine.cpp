#include "engine.hpp"

#include <algorithm>
#include <set>
#include <memory>

#include "algorithms/lsi.hpp"

using namespace SuppleSearch;

Engine::Engine(const Database::shared database, const Database::shared kw, Algorithms::TFIDF::shared algorithm, const Measure::shared measure) :
  measure_(measure),
  database_(database),
  tfidf_(algorithm) {
  make_keywords(kw);

  tfidf_->keywords(keywords_);
  database_tfidf_ = tfidf_->process(database_);
}

void Engine::make_keywords(const Database::shared keywords) {
  std::set<std::string> s;

  for (auto document : keywords->documents()) {
    auto stemmed = document->stemmed_content();
    s.insert(stemmed.begin(), stemmed.end());
  }

  keywords_.insert(keywords_.end(), s.begin(), s.end());
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
