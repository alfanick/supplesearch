cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR supplesearch)
project(${PROJECT_NAME_STR} CXX)
include(ExternalProject)

set(CXX_CLANG_FLAGS "-Wall -Wextra -Wno-unused-parameter -std=c++11 -stdlib=libc++ -O3")
set(CXX_GNU_FLAGS "-std=gnu++11 -Wall -O3")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_CLANG_FLAGS}")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_GNU_FLAGS}")
endif()

set(EXT_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/ext")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(COMMON_INCLUDES "${SOURCE_DIR}")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

add_subdirectory("${SOURCE_DIR}/supplesearch")
add_subdirectory("${SOURCE_DIR}/apps")
