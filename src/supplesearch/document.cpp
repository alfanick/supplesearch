#include "document.hpp"

#include <iostream>

using namespace SuppleSearch;

Document::Document(std::string title, std::string content, Tokenizer::shared tokenizer, Stemmer::shared stemmer) :
  title_(title), content_(content)
{
  auto tokenized = tokenizer->process(content);
  stemmed_content_ = stemmer->process(tokenized);

  for (size_t i = 0; i < tokenized.size(); i++)
   stemming_map_[stemmed_content_[i]] = tokenized[i];
}

const std::string Document::unstem(std::string term) {
  if (stemming_map_.find(term) == stemming_map_.end())
    return term;
  return stemming_map_[term];
}
