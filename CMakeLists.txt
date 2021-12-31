project(qmasr)
cmake_minimum_required(VERSION 3.15)



if(WIN32)
add_definitions(-D_QMASR_API_EXPORT)
else()

include_directories(/opt/qmcds/include/  /opt/qmcds/include/kenlm   /opt/qmcds/include/ctc_decoder  /opt/qmcds/include/kaldi)
message(UNIX)

link_directories(/opt/qmcds/lib /usr/lib)
endif()



include_directories(${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/include)

set(SRC_FILE source/libqmasrapi.cpp source/qmasr.cpp )

set(SRC_FEAT feat/feature_pipeline.cpp  feat/fft.cpp)
add_library(qmasr SHARED  ${SRC_FILE} ${SRC_FEAT})

link_libraries(fst kenlm kenlm_builder kenlm_filter kenlm_interpolate kenlm_util  ctc_decoder onnxruntime yaml-cpp bz2 lzma z)

add_executable(qmasrtest source/testapp.cpp)
target_link_libraries(qmasrtest PUBLIC qmasr  ctc_decoder kenlm kenlm_builder kenlm_filter kenlm_interpolate kenlm_util)