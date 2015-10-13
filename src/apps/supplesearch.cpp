#include <supplesearch/databases/text.hpp>

using namespace SuppleSearch;

int main(int argc, char** argv)
{
  Databases::Text db = Databases::Text::build("data/documents.txt");

  return 0;
}
