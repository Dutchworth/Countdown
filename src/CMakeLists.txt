cmake_minimum_required(VERSION 2.8)
project(src)

set(SRC_FILES
  WordUtils.cpp
  Dictionary.cpp
  StatsUtils.cpp
  FileReading.cpp
  Solver.cpp
  ArgUtils.cpp
)

add_library(srcLib ${SRC_FILES})
