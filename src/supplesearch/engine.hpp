#ifndef ALJ_SUPPLESEARCH_ENGINE_HPP_
#define ALJ_SUPPLESEARCH_ENGINE_HPP_

#include "database.hpp"
#include "measure.hpp"
#include "document.hpp"

namespace SuppleSearch {

using ResultList = std::vector<std::pair<double, Document::shared>>;

class Engine {
  public:
    Engine(const Database::shared database, const Database::shared keywords, const Measure::shared measure);

    ResultList query(const Document::shared q);
    ResultList query(const std::string q);

  private:
    Measure::shared measure_;
    Database::shared database_;
    WordList keywords_;
};

}

#endif
