cmake_minimum_required(VERSION 2.8)

# use c++ 11
set(CMAKE_CXX_STANDARD 11)

# set project name
project( cpp-callback )

# set include directory
include_directories( include )

# source files to compile
add_executable( cpp-callback
                src/main.cpp
                src/example.cpp )

# how to link to a library (OpenCV as example)
#target_link_libraries( cpp-callback ${OpenCV_LIBS} )