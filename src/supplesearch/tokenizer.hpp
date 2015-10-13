#ifndef ALJ_SUPPLESEARCH_TOKENIZER_HPP_
#define ALJ_SUPPLESEARCH_TOKENIZER_HPP_

#include <vector>
#include <string>

namespace SuppleSearch {

using WordList = std::vector<std::string>;

class Tokenizer {
  public:
    typedef std::weak_ptr<Tokenizer> week;
    typedef std::unique_ptr<Tokenizer> unique;
    typedef std::shared_ptr<Tokenizer> shared;

    virtual WordList process(std::string value) = 0;
};

}

#endif
