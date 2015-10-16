cmake_minimum_required(VERSION 2.8.8)
set(PROJECT_NAME_STR supplesearch)
project(${PROJECT_NAME_STR} CXX)
include(ExternalProject)

set(CXX_CLANG_FLAGS "-Wall -Wextra -Wno-unused-parameter -std=c++11 -stdlib=libc++ -O3")
set(CXX_GNU_FLAGS "-std=c++11 -Wall -O3")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE}")

if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_CLANG_FLAGS}")
  set(BLAS_LIB_FLAGS "-framework Accelerate")
  set(SED "gsed")
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${CXX_GNU_FLAGS}")
  set(BLAS_LIB_FLAGS "-lopenblas -llapack")
  set(SED "sed")
endif()

set(EXT_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/ext")
set(SOURCE_DIR "${PROJECT_SOURCE_DIR}/src")
set(COMMON_INCLUDES "${SOURCE_DIR}")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

ExternalProject_Add(arma
  SVN_REPOSITORY "http://svn.code.sf.net/p/arma/code/branch-6.100"
  CMAKE_ARGS -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_DEBUG:PATH=DebugLibs
             -DCMAKE_ARCHIVE_OUTPUT_DIRECTORY_RELEASE:PATH=ReleaseLibs
  PREFIX "${EXT_PROJECTS_DIR}/arma"

  INSTALL_COMMAND ""
  UPDATE_COMMAND ""
)

ExternalProject_Get_Property(arma source_dir)
set(ARMA_INCLUDES_DIR "${source_dir}/include")

ExternalProject_Get_Property(arma binary_dir)
set(ARMA_LIBS_DIR "${binary_dir}")

ExternalProject_Add(porter
  GIT_REPOSITORY "https://github.com/smassung/porter2_stemmer.git"
  PREFIX "${EXT_PROJECTS_DIR}/porter"

  CMAKE_ARGS -DCMAKE_CXX_FLAGS:STRING="-fPIC"
  INSTALL_COMMAND ""
  UPDATE_COMMAND ""

  PATCH_COMMAND ${SED} -i "s/VERSION 3.0.0/VERSION 2.8.0/g" CMakeLists.txt
)

ExternalProject_Get_Property(porter source_dir)
set(PORTER_INCLUDES_DIR "${source_dir}")

ExternalProject_Get_Property(porter binary_dir)
set(PORTER_LIBS_DIR "${binary_dir}")

add_library(armadillo SHARED IMPORTED)
set_target_properties(armadillo PROPERTIES IMPORT_LOCATION "${ARMA_LIBS_DIR}")
message(STATUS "${ARMA_LIBS_DIR}")

add_library(porter_stemmer STATIC IMPORTED)
set_target_properties(porter_stemmer PROPERTIES IMPORT_LOCATION "${PORTER_LIBS_DIR}")
message(STATUS "${PORTER_LIBS_DIR}")

add_subdirectory("${SOURCE_DIR}/supplesearch")
add_subdirectory("${SOURCE_DIR}/apps")
