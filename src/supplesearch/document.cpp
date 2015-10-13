#include "document.hpp"

#include <iostream>

using namespace SuppleSearch;

Document::Document(std::string title, std::string content, Tokenizer::shared tokenizer, Stemmer::shared stemmer) :
  title_(title), content_(content)
{
  stemmed_content_ = stemmer->process(tokenizer->process(content));
  for (auto& k : stemmed_content_) {
    std::cout << k << "|";
  }
  std::cout << std::endl;
}
