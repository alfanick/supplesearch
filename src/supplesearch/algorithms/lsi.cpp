#include "lsi.hpp"

using namespace SuppleSearch::Algorithms;

LSI::LSI(double precision)
  : precision_(precision) {

}

arma::mat LSI::process(SuppleSearch::Database::shared database) {
  auto tfidf = TFIDF::process(database);
  size_t degree = (size_t)(tfidf.n_rows * precision_);

  arma::mat K, D;
  arma::vec s;

  arma::svd(K, s, D, tfidf);

  s.resize(degree);
  K.shed_cols(degree, K.n_cols-1);

  arma::mat Si = arma::diagmat(s).i();
  arma::mat R = (tfidf.t() * K * Si).t();

  return R;
}

// TODO Optimize me
arma::vec LSI::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  auto tfidf = TFIDF::process(database);
  auto document_tfidf = TFIDF::process(database, document);
  size_t degree = (size_t)(tfidf.n_rows * precision_);

  arma::mat K, D;
  arma::vec s;

  arma::svd(K, s, D, tfidf);

  s.resize(degree);
  K.shed_cols(degree, K.n_cols-1);

  arma::mat Si = arma::diagmat(s).i();
  arma::vec R = (document_tfidf.t() * K * Si).t();

  return R;
}
