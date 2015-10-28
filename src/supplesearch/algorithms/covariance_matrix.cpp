#include "covariance_matrix.hpp"

#include <set>
#include <algorithm>

using namespace SuppleSearch::Algorithms;

CovarianceMatrix::CovarianceMatrix(SuppleSearch::Database::shared database, SuppleSearch::Database::shared keywords)
  : database_(database), keywords_(keywords) {
}

std::vector<std::set<size_t>> CovarianceMatrix::find_best(const arma::vec old, std::set<size_t> vis, size_t extra_keywords) {
  std::vector<std::set<size_t>> proposed_queries;
  arma::vec possible(old);

  for (size_t i = 0; i < possible.size(); i++) {
    if (vis.find(i) != vis.end() || old(i) < 0.5)
      continue;
    arma::uword index;
    possible.max(index);

    possible(index) = arma::datum::nan;

    if (extra_keywords > 1) {
      vis.insert(i);
      auto results = find_best(possible, vis, extra_keywords - 1);

      for (auto& result : results) {
        result.insert(index);
      }
      proposed_queries.insert(proposed_queries.end(), results.begin(), results.end());
    }

    std::set<size_t> single;
    single.insert(index);
    proposed_queries.push_back(single);
  }

  return proposed_queries;
}

SuppleSearch::ResultList CovarianceMatrix::process(SuppleSearch::Document::shared query, size_t max_queries, size_t extra_keywords) {
  SuppleSearch::WordList keywords_list = keywords(query);
  TermFrequency term_frequency(keywords_list);

  arma::mat tf = term_frequency.process(database_);
  arma::mat cm = tf * tf.t();

  for (size_t i = 0; i < keywords_list.size(); i++) {
    cm.col(i) /= cm.col(i).max();
  }
  cm.diag().zeros();


  arma::vec possible(keywords_list.size());
  possible.zeros();
  auto stemmed_query = query->stemmed_content();
  for (size_t i = 0; i < stemmed_query.size(); i++) {
    size_t index = std::find(keywords_list.begin(), keywords_list.end(), stemmed_query[i]) - keywords_list.begin();

    arma::vec current = cm.col(index);
    current.elem(arma::find_nonfinite(current)).zeros();
    current(index) = arma::datum::nan;
    possible += current;
  }

  SuppleSearch::ResultList proposed_queries;
  std::set<size_t> visited;
  auto results = find_best(possible, visited, extra_keywords);

  for (auto& result : results) {
    std::string keywords = "";
    double score = 0.0;

    for (auto index : result) {
      if (!keywords.empty())
        keywords += " ";
      keywords += unstem(keywords_list[index]);
      score += possible(index);
    }

    score /= result.size();

    auto doc = database_->build_document("query", keywords);
    proposed_queries.push_back(std::make_pair(score, doc));
  }

  std::sort(proposed_queries.rbegin(), proposed_queries.rend());

  return proposed_queries;
}

const std::string CovarianceMatrix::unstem(std::string term) {
  for (auto document : keywords_->documents()) {
    term = document->unstem(term);
  }
  return term;
}

SuppleSearch::WordList CovarianceMatrix::keywords(SuppleSearch::Document::shared query) {
  SuppleSearch::WordList stemmed;

  std::set<std::string> s;

  for (auto document : keywords_->documents()) {
    auto sc = document->stemmed_content();
    s.insert(sc.begin(), sc.end());
  }

  auto sc = query->stemmed_content();
  s.insert(sc.begin(), sc.end());

  stemmed.insert(stemmed.end(), s.begin(), s.end());

  return stemmed;
}
