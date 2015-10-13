#ifndef ALJ_SUPPLESEARCH_STEMMER_HPP_
#define ALJ_SUPPLESEARCH_STEMMER_HPP_

#include "tokenizer.hpp"

namespace SuppleSearch {

class Stemmer {
  public:
    typedef std::weak_ptr<Stemmer> week;
    typedef std::unique_ptr<Stemmer> unique;
    typedef std::shared_ptr<Stemmer> shared;

    virtual WordList process(WordList input) = 0;
};

}

#endif
