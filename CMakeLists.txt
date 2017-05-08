cmake_minimum_required(VERSION 2.8)
project(Countdown)

# Download and unpack googletest at configure time
configure_file(CMakeLists.txt.in googletest-download/CMakeLists.txt)
execute_process(COMMAND ${CMAKE_COMMAND} -G "${CMAKE_GENERATOR}" .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "CMake step for googletest failed: ${result}")
endif()
execute_process(COMMAND ${CMAKE_COMMAND} --build .
  RESULT_VARIABLE result
  WORKING_DIRECTORY ${CMAKE_BINARY_DIR}/googletest-download )
if(result)
  message(FATAL_ERROR "Build step for googletest failed: ${result}")
endif()

# Prevent overriding the parent project's compiler/linker
# settings on Windows
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

# Add googletest directly to our build. This defines
# the gtest and gtest_main targets.
add_subdirectory(${CMAKE_BINARY_DIR}/googletest-src
                 ${CMAKE_BINARY_DIR}/googletest-build)

# The gtest/gtest_main targets carry header search path
# dependencies automatically when using CMake 2.8.11 or
# later. Otherwise we have to add them here ourselves.
if (CMAKE_VERSION VERSION_LESS 2.8.11)
  include_directories("${gtest_SOURCE_DIR}/include")
endif()

# copying word list to build dir
if (NOT CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_CURRENT_BINARY_DIR)

  # list of files for which we add a copy rule
  set (data_SHADOW english-words/words.txt)

  foreach(item IN LISTS data_SHADOW)
    message(STATUS ${item})
    add_custom_command(
      OUTPUT "${CMAKE_CURRENT_BINARY_DIR}/${item}"
      COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/${item}" "${CMAKE_CURRENT_BINARY_DIR}/${item}"
      DEPENDS "${CMAKE_CURRENT_SOURCE_DIR}/${item}"
    )
  endforeach()
endif()

add_custom_target(data-target ALL DEPENDS "${CMAKE_CURRENT_BINARY_DIR}/english-words/words.txt")

add_definitions(-std=c++11)

add_subdirectory(src)
add_subdirectory(test)

add_executable(Countdown ${src_SOURCE_DIR}/main.cpp)
target_link_libraries(Countdown srcLib)

enable_testing()
add_test(NAME unitTests COMMAND runUnitTests)
