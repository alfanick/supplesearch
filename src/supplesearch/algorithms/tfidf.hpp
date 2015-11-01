#ifndef ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_
#define ALJ_SUPPLESEARCH_ALGORITHMS_TFIDF_HPP_

#include "term_frequency.hpp"
#include "inverse_document_frequency.hpp"


namespace SuppleSearch {
namespace Algorithms {

/**
 * TFIDF algorithm implementation
 */
class TFIDF {
  public:
    //! Shared pointer
    typedef std::shared_ptr<TFIDF> shared;

    TFIDF() {}

    void keywords(SuppleSearch::WordList kw);

    /**
     * Calculate TFIDF represenation
     * of given Database.
     *
     * @param database Database to process
     * @return TFIDF representation
     */
    virtual arma::mat process(SuppleSearch::Database::shared database);

    /**
     * Calculate TFIDF of query outside
     * the Database.
     *
     * @param dataase Database to process
     * @param document Query
     * @return TFIDF representation
     */
    virtual arma::vec process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document);

  protected:
    //! Keywords to process
    SuppleSearch::WordList keywords_;
    //! TF algorithm
    TermFrequency::shared term_frequency_;
    //! IDF algorithm
    InverseDocumentFrequency::shared inverse_document_frequency_;

};

}
}

#endif
