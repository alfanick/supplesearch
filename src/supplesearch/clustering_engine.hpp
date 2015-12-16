#ifndef ALJ_SUPPLESEARCH_CLUSTERING_ENGINE_HPP_
#define ALJ_SUPPLESEARCH_CLUSTERING_ENGINE_HPP_

#include "database.hpp"
#include "measure.hpp"
#include "document.hpp"
#include "algorithms/tfidf.hpp"
#include "algorithms/kmeans.hpp"

#include <map>

namespace SuppleSearch {

using Clusters = std::multimap<size_t, Document::shared>;

class ClusteringEngine {
  public:
    ClusteringEngine(const Database::shared database, const Database::shared keywords, Algorithms::TFIDF::shared algorithm, const Measure::shared measure, Algorithms::KMeans::shared);

    Clusters clusters();

  private:
    //! Used measure
    Measure::shared measure_;
    //! Documents
    Database::shared database_;
    //! Available keywords
    WordList keywords_;
    //! TFIDF
    Algorithms::TFIDF::shared tfidf_;
    //! KMeans
    Algorithms::KMeans::shared kmeans_;
};

}

#endif
