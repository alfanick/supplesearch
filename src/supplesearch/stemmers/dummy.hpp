#ifndef ALJ_SUPPLESEARCH_STEMMERS_DUMMY_HPP_
#define ALJ_SUPPLESEARCH_STEMMERS_DUMMY_HPP_

#include "../stemmer.hpp"

namespace SuppleSearch {
namespace Stemmers {

class Dummy : public Stemmer {
  public:
    WordList process(WordList input) override;
};

}
}

#endif
