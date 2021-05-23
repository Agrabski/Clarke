# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

# Tests
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Language Standard
set(CMAKE_CXX_STANDARD 20)

project ("Clarke")

# Include sub-projects.
add_subdirectory ("Clarke.Messages")

add_subdirectory("Clarke.Messages.Tests")
