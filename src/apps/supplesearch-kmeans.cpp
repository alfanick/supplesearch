#include <supplesearch/clustering_engine.hpp>
#include <supplesearch/databases/text.hpp>
#include <supplesearch/measures/cosine.hpp>

#include <supplesearch/algorithms/tfidf.hpp>
#include <supplesearch/algorithms/kmeans.hpp>

#include <iomanip>
#include <iostream>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  if (argc < 5) {
    std::cout << "Usage: sskm database keywords k max-iterations" << std::endl;
    return 1;
  }

  size_t k = std::stoi(argv[3]);
  Databases::Text::shared db(Databases::Text::build(argv[1]));
  Databases::Text::shared keywords(Databases::Text::build(argv[2]));
  Measure::shared measure(new Measures::Cosine());
  Algorithms::TFIDF::shared tfidf(new Algorithms::TFIDF());
  Algorithms::KMeans::shared kmeans(new Algorithms::KMeans(measure, k, std::stoi(argv[4])));

  ClusteringEngine engine(db, keywords, tfidf, measure, kmeans);

  auto clusters = engine.clusters();

  for (size_t cluster = 0; cluster < k; cluster++) {
    std::cout << "Cluster #" << cluster << std::endl;
    std::cout << "----------" << std::endl;

    auto range = clusters.equal_range(cluster);

    for (auto assigment = range.first; assigment != range.second; ++assigment) {
      std::cout << assigment->second->title() << std::endl;
    }

    std::cout << std::endl;
  }

  return 0;
}
