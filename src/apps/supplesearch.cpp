#include <supplesearch/databases/text.hpp>
#include <supplesearch/algorithms/term_frequency.hpp>
#include <supplesearch/algorithms/inverse_document_frequency.hpp>
#include <supplesearch/algorithms/tfidf.hpp>

#include <supplesearch/engine.hpp>
#include <supplesearch/measures/cosine.hpp>

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

  auto results = engine.query(argv[3]);

  for (auto result : results) {
    std::cout << result.second->title() << " " << result.first << std::endl;
  }


  return 0;
}
