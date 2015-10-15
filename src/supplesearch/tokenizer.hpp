#ifndef ALJ_SUPPLESEARCH_TOKENIZER_HPP_
#define ALJ_SUPPLESEARCH_TOKENIZER_HPP_

#include <memory>
#include <vector>
#include <string>

namespace SuppleSearch {

//! List of words
using WordList = std::vector<std::string>;

/**
 * Tokenizer tokenizes simple text input to
 * list of tokens (terms).
 */
class Tokenizer {
  public:
    //! Weak pointer
    typedef std::weak_ptr<Tokenizer> week;
    //! Shared pointer
    typedef std::shared_ptr<Tokenizer> shared;
    //! Unique pointer
    typedef std::unique_ptr<Tokenizer> unique;

    /**
     * Transform input into tokens.
     *
     * @param value Input
     * @return Tokenized input
     */
    virtual WordList process(std::string value) = 0;
};

}

#endif
