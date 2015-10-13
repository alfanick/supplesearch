#include "text.hpp"

#include "../tokenizers/whitespace.hpp"
#include "../stemmers/porter.hpp"

#include <iostream>
#include <fstream>

using namespace SuppleSearch::Databases;

size_t Text::insert_from_file(std::string filename) {
  std::ifstream input(filename);
  std::string line;
  std::string current_document;
  std::string current_title;
  size_t added = 0;

  while (std::getline(input, line)) {
    if (line == "\r" || line.empty()) {
      Document::unique document(new Document(current_title, current_document, tokenizer_, stemmer_));
      insert(std::move(document));
      added++;
      current_document = "";
      current_title = "";
    } else {
      current_document += line;
      current_document += "\n";

      if (current_title.empty())
        current_title = line;
    }
  }

  if (!current_document.empty()) {
      Document::unique document(new Document(current_title, current_document, tokenizer_, stemmer_));
      insert(std::move(document));
      added++;
  }

  return added;
}

Text Text::build(std::string filename) {
  Tokenizer::shared tokenizer(new Tokenizers::Whitespace());
  Stemmer::shared stemmer(new Stemmers::Porter());
  Text db(tokenizer, stemmer);

  std::cout << db.insert_from_file(filename) << std::endl;

  return db;
}
