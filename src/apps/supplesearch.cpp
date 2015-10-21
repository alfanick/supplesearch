#include <supplesearch/engine.hpp>
#include <supplesearch/databases/text.hpp>
#include <supplesearch/measures/cosine.hpp>

#include <supplesearch/algorithms/inverse_document_frequency.hpp>

#include <iomanip>
#include <iostream>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  if (argc != 4) {
    std::cout << "Usage: ss database keywords query" << std::endl;
    return 1;
  }

  Databases::Text::shared db(Databases::Text::build(argv[1]));
  Databases::Text::shared keywords(Databases::Text::build(argv[2]));
  Measure::shared measure(new Measures::Cosine());
  Engine engine(db, keywords, measure);

  // Algorithms::InverseDocumentFrequency idf(db);
  // auto qt = idf.process(engine.keywords());
  // int i = 0;
  // for (auto stem : engine.keywords()) {
  //   std::cout << qt(i++) << "\t" << stem << std::endl;
  // }

  auto results = engine.query(argv[3]);

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
