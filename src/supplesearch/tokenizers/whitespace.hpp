#ifndef ALJ_SUPPLESEARCH_TOKENIZERS_WHITESPACE_HPP_
#define ALJ_SUPPLESEARCH_TOKENIZERS_WHITESPACE_HPP_

#include "../tokenizer.hpp"

namespace SuppleSearch {
namespace Tokenizers {

/**
 * Naive tokenizer. Tokenize input by
 * whitespaces. Tokens are lowercased and
 * every nonalfanumeric character is removed.
 */
class Whitespace : public Tokenizer {
  public:
    /**
     * Transform content into tokens.
     *
     * @params input Content
     * @return Tokens
     */
    WordList process(std::string input) override;
};

}
}

#endif
