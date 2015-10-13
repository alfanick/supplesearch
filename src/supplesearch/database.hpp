#ifndef ALJ_SUPPLESEARCH_DATABASE_HPP_
#define ALJ_SUPPLESEARCH_DATABASE_HPP_

#include "document.hpp"

#include <vector>

namespace SuppleSearch {

/**
 * List of Document
 */
using DocumentList = std::vector<Document::unique>;

/**
 * Database is set of Document indexed in
 * SuppleSearch
 * */
class Database {
  public:
    /**
     * Create new Database, uses given tokenizer and stemmer
     * for new Document.
     *
     * @param tokenizer Tokenizer to use
     * @param stemmer Stemmer to use
     */
    Database(const Tokenizer::shared tokenizer, const Stemmer::shared stemmer) :
      tokenizer_(tokenizer), stemmer_(stemmer) { }

    /**
     * Add a document to the database
     *
     * @param document Document to add
     */
    void insert(Document::unique document);

    /**
     * Remove a document from the database
     *
     * @param document Document to remove
     */
    void remove(Document::unique document);

    /**
     * Return available Document
     *
     * @return Document list
     */
    DocumentList& documents() { return documents_; }

  protected:
    //! Tokenizer used for documents
    Tokenizer::shared tokenizer_;
    //! Stemmer used for documents;
    Stemmer::shared stemmer_;

  private:
    //! List of documents
    DocumentList documents_;
};

}

#endif
