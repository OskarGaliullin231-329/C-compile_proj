cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_executable(main)

target_sources(main PRIVATE main.cpp)

add_subdirectory(CmdArgParser)
add_subdirectory(Logger)
add_subdirectory(Preproc)
add_subdirectory(Translator)
