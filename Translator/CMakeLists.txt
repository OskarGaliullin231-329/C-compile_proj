cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_library(Translator)

target_sources(Translator
  PRIVATE
    src/Lexer.cpp
    # src/Parser.cpp
    # src/SemAn.cpp
)

target_include_directories(Translator PUBLIC include)

target_link_libraries(Translator PRIVATE AST)
