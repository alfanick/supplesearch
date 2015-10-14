#ifndef ALJ_SUPPLESEARCH_DATABASES_TEXT_HPP_
#define ALJ_SUPPLESEARCH_DATABASES_TEXT_HPP_

#include "../database.hpp"

namespace SuppleSearch {
namespace Databases {

/**
 * Text database is represented in single text file.
 * Each Document is separated by empty line. First line
 * of each Document represents title although title
 * also is part of its content.
 */
class Text : public Database {
  public:
    using Database::Database;

    //! Shared pointer
    typedef std::shared_ptr<Text> shared;

    /**
     * Insert new Documents from file into
     * existing Database.
     *
     * @param filename Filename of the database
     * @return Number of added documents
     */
    size_t insert_from_file(std::string filename);

    /**
     * Create new Text Database from file.
     *
     * @param filename Filename of the database
     * @return Database
     */
    static Text::shared build(std::string filename);

};

}
}

#endif
