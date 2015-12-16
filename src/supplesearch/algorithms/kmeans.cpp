#include "kmeans.hpp"

#include <set>

using namespace SuppleSearch::Algorithms;

KMeans::KMeans(Measure::shared measure, size_t k, size_t max_iterations)
  : k_(k), max_iterations_(max_iterations), measure_(measure) {
  srand(time(0));
  // srand(123);
}

arma::vec KMeans::process(arma::mat documents) {
  arma::mat distances = arma::zeros(k_, documents.n_cols);
  arma::mat centroids = arma::zeros(k_, documents.n_rows);
  arma::vec current_clusters = arma::zeros(documents.n_cols);

  std::set<size_t> used_documents;

  // random seed
  for (size_t i = 0; i < k_; i++) {
    size_t index;

    do {
      index = rand() % documents.n_cols;
    } while(used_documents.find(index) != used_documents.end());

    centroids.row(i) = documents.col(index).t();
    used_documents.insert(index);
  }

  std::multimap<arma::uword, size_t> previous_clusters;

  for (size_t iteration = 0; iteration < max_iterations_; iteration++) {
    // calculate distances
    for (size_t document = 0; document < documents.n_cols; document++) {
      for (size_t i = 0; i < k_; i++) {
        distances(i, document) = measure_->compare((arma::vec)documents.col(document), centroids.row(i).t());
      }
    }

    bool has_changed = false;

    // find closest centroid and assign to cluster
    for (size_t document = 0; document < documents.n_cols; document++) {
      arma::uword cluster;

      distances.col(document).max(cluster);

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
      arma::vec mean = arma::zeros(documents.n_rows);
      size_t size = 0;

      for (size_t document = 0; document < current_clusters.n_rows; document++) {
        if (current_clusters(document) != cluster)
          continue;

        mean += documents.col(document);
        size++;
      }

      centroids.row(cluster) = mean.t();
    }
  }

  return current_clusters;
}

