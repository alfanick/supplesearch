#include <supplesearch/databases/text.hpp>
#include <supplesearch/algorithms/term_frequency.hpp>
#include <supplesearch/algorithms/inverse_document_frequency.hpp>
#include <supplesearch/algorithms/tfidf.hpp>

#include <iostream>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  if (argc != 3) {
    std::cout << "Usage: ss database keywords" << std::endl;
    return 1;
  }

  Databases::Text::shared db(Databases::Text::build(argv[1]));
  Databases::Text::shared keywords(Databases::Text::build(argv[2]));

  auto kw = keywords->documents().front()->stemmed_content();

  Algorithms::TFIDF tfidf(kw);
  tfidf.process(db).t().raw_print();

  return 0;
}
