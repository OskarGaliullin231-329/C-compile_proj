cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_library(Preproc)

target_sources(Preproc
  PRIVATE
    src/Preproc.cpp
)

target_include_directories(Preproc
  PUBLIC include
)

target_link_libraries(Preproc
  PUBLIC Logger
)
