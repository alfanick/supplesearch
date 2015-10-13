#include "porter.hpp"

using namespace SuppleSearch::Stemmers;

SuppleSearch::WordList Porter::process(SuppleSearch::WordList input) {
  for (auto& term : input) {
    Porter2Stemmer::trim(term);
    Porter2Stemmer::stem(term);
  }

  return input;
}
