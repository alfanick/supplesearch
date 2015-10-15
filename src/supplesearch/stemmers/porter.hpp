#ifndef ALJ_SUPPLESEARCH_STEMMERS_PORTER_HPP_
#define ALJ_SUPPLESEARCH_STEMMERS_PORTER_HPP_

#include "../stemmer.hpp"

#include <memory>

#include <porter2_stemmer.h>

namespace SuppleSearch {
namespace Stemmers {

/**
 * Porter2 stemmer
 */
class Porter : public Stemmer {
  public:
    /**
     * Stemm input using Porter2 via external lib
     *
     * @param input Tokenized content
     * @return Stemmed content
     */
    WordList process(WordList input) override;
};

}
}

#endif
