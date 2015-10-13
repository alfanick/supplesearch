#include <supplesearch/databases/text.hpp>

#include <iostream>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  auto db = Databases::Text::build("data/documents.txt");
  auto keywords = Databases::Text::build("data/keywords.txt");

  for (auto doc : db.documents()) {
    std::cout << doc->title() << std::endl;
  }

  return 0;
}
