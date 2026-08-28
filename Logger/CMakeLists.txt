cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_library(Logger)

target_sources(Logger
  PRIVATE
    src/StdLogger.cpp
)

target_include_directories(Logger
  PUBLIC include
)
