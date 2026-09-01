cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_library(AST)

target_souces(AST
  PRIVATE
    src/ # src files are to be added
)

target_include_directories(AST PUBLIC include)
