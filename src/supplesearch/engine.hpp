#ifndef ALJ_SUPPLESEARCH_ENGINE_HPP_
#define ALJ_SUPPLESEARCH_ENGINE_HPP_

#include "database.hpp"
#include "measure.hpp"
#include "document.hpp"
#include "algorithms/tfidf.hpp"

namespace SuppleSearch {

/**
 * List of search results. First value is score,
 * second is the Document.
 */
using ResultList = std::vector<std::pair<double, Document::shared>>;

/**
 * Search engine working on given database and keywords
 * with given measure.
 */
class Engine {
  public:
    /**
     * Create new Engine instance.
     *
     * @param database Available documents
     * @param keywords Available keywords
     * @param algorithm Used scoring algorithm
     * @param measure Used measure
     */
    Engine(const Database::shared database, const Database::shared keywords, Algorithms::TFIDF::shared algorithm, const Measure::shared measure);

    /**
     * Query Database.
     *
     * @param q Query
     * @return Results
     */
    ResultList query(const Document::shared q);

    /**
     * Query Database via string
     *
     * @param q Query
     * @return Results
     */
    ResultList query(const std::string q);

    /**
     * Unique keywords
     *
     * @return Keywords
     */
    WordList keywords() { return keywords_; }

  private:
    void make_keywords(const Database::shared keywords);

    //! Used measure
    Measure::shared measure_;
    //! Documents
    Database::shared database_;
    //! Available keywords
    WordList keywords_;
    //! TFIDF
    Algorithms::TFIDF::shared tfidf_;
    //! Database TFIDF scores
    arma::mat database_tfidf_;
};

}

#endif
