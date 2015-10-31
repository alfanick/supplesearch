#include <supplesearch/engine.hpp>
#include <supplesearch/databases/text.hpp>
#include <supplesearch/measures/cosine.hpp>

#include <supplesearch/algorithms/inverse_document_frequency.hpp>
#include <supplesearch/algorithms/covariance_matrix.hpp>
#include <supplesearch/algorithms/lsi.hpp>

#include <iomanip>
#include <iostream>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  if (argc < 5) {
    std::cout << "Usage: ss database keywords query precision extra" << std::endl;
    return 1;
  }

  double precision = std::stof(argv[4]);

  Databases::Text::shared db(Databases::Text::build(argv[1]));
  Databases::Text::shared keywords(Databases::Text::build(argv[2]));
  Measure::shared measure(new Measures::Cosine());
  Algorithms::TFIDF::shared tfidf(precision < 1.0 ? new Algorithms::LSI(precision) : new Algorithms::TFIDF());
  Engine engine(db, keywords, tfidf, measure);
  Algorithms::CovarianceMatrix covariance_matrix(db, keywords);

  auto query = db->build_document("query", argv[3]);
  auto results = engine.query(query);

  std::cout << "Results for \"" << argv[3] << "\"";

  if (argc == 6) {
    auto proposed_queries = covariance_matrix.process(query, 10, std::stoul(argv[5]));

    std::cout << " (consider ";
    size_t max_queries = proposed_queries.size() > 10 ? 10 : proposed_queries.size();
    for (size_t i = 0; i < max_queries; i++) {
      std::cout << "\"" << argv[3] << ' ' << proposed_queries[i].second->content() << "\" [" << std::setprecision(4) << proposed_queries[i].first << "] ";
    }
    std::cout << ")";
  }

  std::cout << ":" << std::endl << std::endl;

  for (auto result : results) {
    if (!isnan(result.first) && (result.first > 0)) {
      std::cout << std::setw(8) << std::setprecision(6) << result.first << "\t" << result.second->title() << std::endl << "--------" << std::endl;
      std::cout << result.second->content();
      for (auto stem : result.second->stemmed_content()) {
        std::cout << stem << ' ';
      }
      std::cout << std::endl << std::endl << std::endl;
    }
  }


  return 0;
}
