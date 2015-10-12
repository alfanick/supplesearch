file(GLOB APPS_SRC_FILES "${PROJECT_SOURCE_DIR}/src/apps/*.cpp")

include_directories(${ARMA_INCLUDES_DIR} ${COMMON_INCLUDES})
link_directories(${ARMA_LIBS_DIR})

add_executable(ss "${PROJECT_SOURCE_DIR}/src/apps/supplesearch.cpp")
add_dependencies(ss arma)
target_link_libraries(ss supplesearch)
install(TARGETS ss DESTINATION bin)
