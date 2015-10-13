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
    typedef std::weak_ptr<Document> weak;
    typedef std::shared_ptr<Document> shared;
    typedef std::unique_ptr<Document> unique;

    Document(std::string title, std::string content, const Tokenizer::shared tokenizer, const Stemmer::shared stemmer);
    Document(const Tokenizer::shared tokenizer, const Stemmer::shared stemmer) :
      Document("", "", tokenizer, stemmer) {}

    const std::string content() { return content_; }
    WordList stemmed_content() { return stemmed_content_; }

  private:
    std::string title_;
    std::string content_;
    WordList stemmed_content_;
};

}

#endif
