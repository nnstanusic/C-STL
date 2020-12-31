# CMakeList.txt : CMake project for C STL, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("C STL")

# Add source to this project's executable.
add_executable (CSTL "C STL.c")

target_include_directories(CSTL PRIVATE "include")
# TODO: Add tests and install targets if needed.
