# CMakeList.txt : CMake project for Clarke.Messages, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_library (Clarke.Messages STATIC "Clarke.Messages.cpp" "Clarke.Messages.h" "Message.hpp" "MessageOperator.hpp")

# TODO: Add tests and install targets if needed.
