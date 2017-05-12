cmake_minimum_required(VERSION 2.8)
project(test)

set(TEST_SOURCES
  RunAllTests.cpp
  WordUtilsTests.cpp
  DictionaryTests.cpp
  StatsUtilsTests.cpp
  FileReadingTests.cpp
  SolverTests.cpp
  ArgUtilsTests.cpp
)

include_directories(${src_SOURCE_DIR})

add_executable(countdown-runUnitTests ${TEST_SOURCES})
target_link_libraries(countdown-runUnitTests srcLib gtest gtest_main)
