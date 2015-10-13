#ifndef ALJ_SUPPLESEARCH_STEMMERS_DUMMY_HPP_
#define ALJ_SUPPLESEARCH_STEMMERS_DUMMY_HPP_

#include "../stemmer.hpp"

namespace SuppleSearch {
namespace Stemmers {

/**
 * Dummy stemmer - does nothing
 */
class Dummy : public Stemmer {
  public:
    /**
     * Does nothing
     *
     * @param input Input
     * @return Same as input
     */
    WordList process(WordList input) override;
};

}
}

#endif
