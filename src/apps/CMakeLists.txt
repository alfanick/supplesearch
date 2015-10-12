file(GLOB APPS_SRC_FILES "${PROJECT_SOURCE_DIR}/src/apps/*.cpp")

include_directories(${COMMON_INCLUDES})

add_executable(ss "${PROJECT_SOURCE_DIR}/src/apps/supplesearch.cpp")
target_link_libraries(ss supplesearch)
install(TARGETS ss DESTINATION bin)
