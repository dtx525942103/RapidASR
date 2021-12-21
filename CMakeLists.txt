cmake_minimum_required(VERSION 3.18)
project(RapidASR)

add_subdirectory(thirdpart/kaldi-feat)
add_subdirectory(thirdpart/openfst)
add_subdirectory(thirdpart/kenlm)
add_subdirectory(thirdpart/ctc-decoder)
add_subdirectory(thirdpart/eigen)

set(SRC cpp/rapidasr.cpp)
add_libraries(rapidasr SHARED ${SRC})
add_executable(test cpp/test.cpp)

