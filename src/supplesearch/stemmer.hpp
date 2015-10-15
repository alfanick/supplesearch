#ifndef ALJ_SUPPLESEARCH_STEMMER_HPP_
#define ALJ_SUPPLESEARCH_STEMMER_HPP_

#include "tokenizer.hpp"

#include <memory>

namespace SuppleSearch {

/**
 * Stemmer converts terms (words) to basic
 * forms.
 */
class Stemmer {
  public:
    //! Weak pointer
    typedef std::weak_ptr<Stemmer> week;
    //! Shared pointer
    typedef std::shared_ptr<Stemmer> shared;
    //! Unique pointer
    typedef std::unique_ptr<Stemmer> unique;

    /**
     * Run stemmer on input word list
     *
     * @param input Tokenized input
     * @return Stemmed input
     */
    virtual WordList process(WordList input) = 0;
};

}

#endif
