set(SUPPLESEARCH_INCLUDES "${PROJECT_SOURCE_DIR}/src/supplesearch")
file(GLOB SUPPLESEARCH_SRC_FILES "${PROJECT_SOURCE_DIR}/src/supplesearch/*.cpp")

include_directories(${COMMON_INCLUDES} ${SUPPLESEARCH_INCLUDES})

add_library(supplesearch SHARED ${SUPPLESEARCH_SRC_FILES})

install (TARGETS supplesearch DESTINATION bin)
