cmake_minimum_required(VERSION 3.19)
project(kaldi-feat)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})


aux_source_directory(feat SRC_FEAT)
list(REMOVE_ITEM SRC_FEAT  "wave-reader-test.cc")

set(LIBNAME kaldi-feat)
add_library(${LIBNAME} ${SRC_FEAT})