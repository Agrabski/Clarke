# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.10)

project ("Clarke")

# Tests
enable_testing()

# Language Standard
set(CMAKE_CXX_STANDARD 20)


# Include sub-projects.
add_subdirectory ("Clarke.Messages")

add_subdirectory("Clarke.Messages.Tests")

add_subdirectory("Clarke.Engine.Core")

add_subdirectory("Clarke.Engine.Entropy")

add_subdirectory("Clarke.Engine.Core.Tests")
