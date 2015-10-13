#ifndef ALJ_SUPPLESEARCH_DATABASE_HPP_
#define ALJ_SUPPLESEARCH_DATABASE_HPP_

#include "document.hpp"

#include <vector>

namespace SuppleSearch {

using DocumentList = std::vector<Document::unique>;

class Database {
  public:
    void insert(Document::unique document);
    void remove(Document::unique document);

    DocumentList& documents() { return documents_; }

  private:
    DocumentList documents_;
};

}

#endif
