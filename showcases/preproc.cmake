cmake_minimum_required(VERSION 3.16)

project(C-compiler-proj)

add_executable(preproc)

target_sources(preproc
  PRIVATE preproc_sc.cpp
)

# target_include_direcotories(preproc
#   PUBLIC ../CmdArgParser/include \
#          ../Logger/include \
#          ../Preproc/include
# )

target_link_libraries(preproc
  PRIVATE
    Logger
    Preproc
    CmdArgParser
)
