#include "database.hpp"

#include <algorithm>

using namespace SuppleSearch;

void Database::insert(Document::shared document) {
  documents_.push_back(std::move(document));
}

void Database::remove(Document::shared document) {
  documents_.erase(std::remove(documents_.begin(),
                               documents_.end(),
                               document),
                   documents_.end());

}
