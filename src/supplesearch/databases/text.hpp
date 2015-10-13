#ifndef ALJ_SUPPLESEARCH_DATABASES_TEXT_HPP_
#define ALJ_SUPPLESEARCH_DATABASES_TEXT_HPP_

#include "../database.hpp"

namespace SuppleSearch {
namespace Databases {

class Text : public Database {
  public:
    Text(const Tokenizer::shared tokenizer, const Stemmer::shared stemmer) :
      tokenizer_(tokenizer), stemmer_(stemmer) { }

    size_t insert_from_file(std::string filename);

    static Text build(std::string filename);

  private:
    Tokenizer::shared tokenizer_;
    Stemmer::shared stemmer_;
};

}
}

#endif
