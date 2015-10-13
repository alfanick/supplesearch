#ifndef ALJ_SUPPLESEARCH_DOCUMENT_HPP_
#define ALJ_SUPPLESEARCH_DOCUMENT_HPP_

#include "tokenizer.hpp"
#include "stemmer.hpp"
#include "stemmers/dummy.hpp"

namespace SuppleSearch {

/**
 * Document describes single text document which
 * is indexable and searchable.
 */
class Document {
  public:
    //! Weak pointer
    typedef std::weak_ptr<Document> weak;
    //! Shared pointer
    typedef std::shared_ptr<Document> shared;
    //! Unique pointer
    typedef std::unique_ptr<Document> unique;

    /**
     * Create new Document. The document's content
     * is tokenized and then stemmed. The document
     * is immutable.
     *
     * @param title Title of the document (not processed)
     * @param content Content to be stemmed
     * @param tokenizer Tokenizer to use
     * @param stemmer Stemmer to use
     */
    Document(std::string title, std::string content, const Tokenizer::shared tokenizer, const Stemmer::shared stemmer);

    /**
     * Return unprocessed content
     *
     * @return Content
     */
    const std::string content() { return content_; }

    /**
     * Return stemmed content
     *
     * @return Content
     */
    WordList stemmed_content() { return stemmed_content_; }

  private:
    //! Document title
    std::string title_;
    //! Document content
    std::string content_;
    //! Processed stemmed content
    WordList stemmed_content_;
};

}

#endif
