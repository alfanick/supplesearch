#include "whitespace.hpp"

#include <sstream>
#include <algorithm>
#include <cctype>

using namespace SuppleSearch::Tokenizers;

SuppleSearch::WordList Whitespace::process(std::string input) {
  WordList result;

  std::istringstream buffer(input);
  std::string token;

  while (buffer >> token) {
    token.erase(std::remove_if(token.begin(), token.end(), [](char c) {
      return !std::isalnum(c);
    }), token.end());

    std::transform(token.begin(), token.end(), token.begin(), ::tolower);

    if (!token.empty())
      result.push_back(token);
  }

  return result;
}
