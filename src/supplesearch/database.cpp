#include "database.hpp"

#include <algorithm>

using namespace SuppleSearch;

void Database::insert(Document::shared document) {
  documents_.push_back(document);
}

void Database::remove(Document::shared document) {
  documents_.erase(std::remove(documents_.begin(),
                               documents_.end(),
                               document),
                   documents_.end());

}

Document::shared Database::build_document(std::string title, std::string content) {
  Document::shared document(new Document(title, content, tokenizer_, stemmer_));
  return document;
}
