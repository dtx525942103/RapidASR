cmake_minimum_required(VERSION 3.15)
project(ctc_decoder)
set(LIBNAME ctc_decoder)
set(MAIN_SRC "ctc_beam_search_decoder.cpp" "decoder_utils.cpp" "path_trie.cpp" "scorer.cpp")
add_library(${LIBNAME} ${MAIN_SRC})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
if(WIN32)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/win-dep/include)

link_directories(${CMAKE_CURRENT_SOURCE_DIR}/win-dep/lib/x64)
else()
include_directories(${SDK_ROOT}include ${SDK_ROOT}include/kenlm)

link_directories(${SDK_ROOT}lib)


endif()


link_directories(${LIBNAME} fst)

set(APPNAME "testapp")
add_executable(${APPNAME} test/test.cpp)

target_link_libraries(${APPNAME} ctc_decoder)


