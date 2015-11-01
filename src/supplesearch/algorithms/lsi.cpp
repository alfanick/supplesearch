#include "lsi.hpp"

using namespace SuppleSearch::Algorithms;

LSI::LSI(double precision)
  : precision_(precision) {

}

arma::mat LSI::process(SuppleSearch::Database::shared database) {
  tfidf_ = TFIDF::process(database);
  degree_ = (size_t)(tfidf_.n_rows * precision_);

  arma::mat D;
  arma::vec s;

  arma::svd(K_, s, D, tfidf_);

  s.resize(degree_);
  K_.shed_cols(degree_, K_.n_cols-1);
  D.shed_cols(degree_, D.n_cols-1);

  Si_ = arma::diagmat(s).i();

  return D.t();
}

arma::vec LSI::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  auto document_tfidf = TFIDF::process(database, document);

  arma::vec R = (document_tfidf.t() * K_ * Si_).t();

  return R;
}
