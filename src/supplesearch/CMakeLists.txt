set(SUPPLESEARCH_INCLUDES "${PROJECT_SOURCE_DIR}/src/supplesearch")
file(GLOB_RECURSE SUPPLESEARCH_SRC_FILES "${PROJECT_SOURCE_DIR}/src/supplesearch/*.cpp" "${PORTER_INCLUDES_DIR}/*.cpp")

include_directories(${COMMON_INCLUDES} ${SUPPLESEARCH_INCLUDES} ${PORTER_INCLUDES_DIR} ${ARMA_INCLUDES_DIR})

add_library(supplesearch SHARED ${SUPPLESEARCH_SRC_FILES})
target_link_libraries(supplesearch "${BLAS_LIB_FLAGS}")

install (TARGETS supplesearch DESTINATION bin)
