cmake_minimum_required(VERSION 3.4.1 FATAL_ERROR)
project(bvcc)

# CMake build type
if(NOT CMAKE_BUILD_TYPE)
    message(STATUS "no CMAKE_BUILD_TYPE given -- setting to Release")
    set(CMAKE_BUILD_TYPE "Release")
endif(NOT CMAKE_BUILD_TYPE)

# C++ standard
set(CXX_STANDARD c++17)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -std=gnu++17 ${GCC_WARNINGS}")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -DNDEBUG -march=native")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -O0 -ggdb -DDEBUG")

include_directories(${CMAKE_SOURCE_DIR})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
add_subdirectory(test)
