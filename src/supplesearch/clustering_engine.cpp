#include "clustering_engine.hpp"

#include <set>

using namespace SuppleSearch;

ClusteringEngine::ClusteringEngine(const Database::shared database, const Database::shared kw, Algorithms::TFIDF::shared algorithm, const Measure::shared measure, Algorithms::KMeans::shared kmeans) :
  measure_(measure),
  database_(database),
  tfidf_(algorithm),
  kmeans_(kmeans) {
  WordList keywords;
  std::set<std::string> s;

  for (auto document : kw->documents()) {
    auto stemmed = document->stemmed_content();
    s.insert(stemmed.begin(), stemmed.end());
  }

  keywords.insert(keywords_.end(), s.begin(), s.end());

  algorithm->keywords(keywords);
}

Clusters ClusteringEngine::clusters() {
  Clusters results;

  arma::vec clusters = kmeans_->process(tfidf_->process(database_));

  for (size_t i = 0; i < clusters.n_rows; i++) {
    results.emplace(clusters(i), database_->documents().at(i));
  }

  return results;
}
