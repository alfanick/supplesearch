#include "lsi.hpp"

using namespace SuppleSearch::Algorithms;

LSI::LSI(double precision)
  : precision_(precision) {

}

arma::mat LSI::process(SuppleSearch::Database::shared database) {
  auto tfidf = TFIDF::process(database);
  size_t degree = (size_t)(tfidf.n_rows * precision_);

  arma::mat tfidf_squared(tfidf);
  tfidf_squared.resize(tfidf.n_cols, tfidf.n_cols);

  arma::mat K, D, R;
  arma::vec s;

  arma::svd(K, s, D, tfidf_squared);

  s.resize(degree);
  K.shed_cols(degree, K.n_cols-1);
  D.shed_cols(degree, D.n_cols-1);

  R = K * arma::diagmat(s) * D.t();

  R.resize(arma::size(tfidf));

  return R;
}

// TODO OPTIMIZE ME!
arma::vec LSI::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  auto tfidf = TFIDF::process(database);
  auto document_tfidf = TFIDF::process(database, document);
  size_t degree = (size_t)(tfidf.n_rows * precision_);

  arma::mat tfidf_squared(tfidf);
  tfidf_squared.resize(tfidf.n_cols, tfidf.n_cols);

  arma::mat K, D, Si;
  arma::vec s;

  arma::svd(K, s, D, tfidf_squared);

  s.resize(degree);
  K.shed_cols(degree, K.n_cols-1);
  D.shed_cols(degree, D.n_cols-1);

  Si = arma::diagmat(s).i();

  document_tfidf.resize(tfidf.n_cols);
  arma::mat document_tfidf_mat(arma::size(K));
  document_tfidf_mat.col(0) = document_tfidf;
  arma::mat R = document_tfidf.t() * K * Si;
  arma::vec r(R.row(0).t());
  r.resize(tfidf.n_rows);
  return r;
}
