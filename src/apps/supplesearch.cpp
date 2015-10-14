#include <supplesearch/engine.hpp>
#include <supplesearch/databases/text.hpp>
#include <supplesearch/measures/cosine.hpp>

#include <supplesearch/algorithms/inverse_document_frequency.hpp>

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

  // Algorithms::InverseDocumentFrequency idf(db);
  // auto qt = idf.process(keywords->documents().front()->stemmed_content());
  // int i = 0;
  // for (auto stem : keywords->documents().front()->stemmed_content()) {
  //   std::cout << qt(i++) << "\t" << stem << std::endl;
  // }

  Engine engine(db, keywords, measure);

  auto results = engine.query(argv[3]);

  for (auto result : results) {
    if (!isnan(result.first) && (result.first > 0)) {
      std::cout << result.second->title() << " " << result.first << std::endl;
    }
  }


  return 0;
}
