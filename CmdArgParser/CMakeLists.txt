cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_library(CmdArgParser)

target_sources(CmdArgParser
  PRIVATE
    src/CmdArgParser.cpp
)

target_include_directories(CmdArgParser
  PUBLIC include
)
