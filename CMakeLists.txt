cmake_minimum_required(VERSION 3.18)
project(RapidASR)

add_subdirectory(thirdpart/kaldi-feat)
add_subdirectory(thirdpart/openfst)
add_subdirectory(thirdpart/kenlm)
add_subdirectory(thirdpart/ctc-decoder)

#add_executable(test cpp/test.cpp)

