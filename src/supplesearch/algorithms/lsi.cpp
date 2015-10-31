#include "lsi.hpp"

using namespace SuppleSearch::Algorithms;

LSI::LSI(size_t degree)
  : degree_(degree) {

}

arma::mat LSI::process(SuppleSearch::Database::shared database) {
  return TFIDF::process(database);
}

arma::vec LSI::process(SuppleSearch::Database::shared database, SuppleSearch::Document::shared document) {
  return TFIDF::process(database, document);
}
