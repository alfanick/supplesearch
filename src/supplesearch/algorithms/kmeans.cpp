#include "kmeans.hpp"

#include <map>

using namespace SuppleSearch::Algorithms;

KMeans::KMeans(Measure::shared measure, size_t k, size_t max_iterations)
  : k_(k), max_iterations_(max_iterations), measure_(measure) {
  srand(time(0));
}

arma::vec KMeans::process(arma::mat documents) {
  arma::mat distances = arma::zeros(k_, documents.n_cols);
  arma::mat centroids = arma::zeros(k_, documents.n_rows);
  arma::vec current_clusters = arma::zeros(documents.n_cols);

  // random seed
  for (size_t i = 0; i < k_; i++) {
    centroids.row(i) = documents.col(rand() % documents.n_cols).t();
  }

  std::multimap<arma::uword, size_t> previous_clusters;

  for (size_t iteration = 0; iteration < max_iterations_; iteration++) {
    // calculate distances
    for (size_t document = 0; document < documents.n_cols; document++) {
      for (size_t i = 0; i < k_; i++) {
        distances(i, document) = measure_->compare((arma::vec)documents.col(document), centroids.row(i).t());
      }
    }

    std::multimap<arma::uword, size_t> clusters;
    bool has_changed = false;

    // find closest centroid and assign to cluster
    for (size_t document = 0; document < documents.n_cols; document++) {
      arma::uword cluster;

      distances.col(document).max(cluster);
      clusters.emplace(cluster, document);

      if (current_clusters(document) != cluster) {
        current_clusters(document) = cluster;
        has_changed = true;
      }
    }

    if (!has_changed) {
      std::cout << "Done after " << iteration << " iterations." << std::endl << std::endl;
      break;
    }

    // calculate new centroid
    for (size_t cluster = 0; cluster < k_; cluster++) {
      auto range = clusters.equal_range(cluster);
      size_t size = 0;
      arma::vec mean = arma::zeros(documents.n_rows);

      for (auto assignment = range.first; assignment != range.second; ++assignment) {
        mean += documents.col(assignment->second);

        size++;
      }

      centroids.row(cluster) = mean.t();
    }
  }

  return current_clusters;
}

