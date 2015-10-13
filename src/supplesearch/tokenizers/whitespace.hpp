#ifndef ALJ_SUPPLESEARCH_TOKENIZERS_WHITESPACE_HPP_
#define ALJ_SUPPLESEARCH_TOKENIZERS_WHITESPACE_HPP_

#include "../tokenizer.hpp"

namespace SuppleSearch {
namespace Tokenizers {

class Whitespace : public Tokenizer {
  public:
    WordList process(std::string input) override;
};

}
}

#endif
