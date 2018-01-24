cmake_minimum_required(VERSION 2.8)

project(fusiongb)
file(GLOB_RECURSE SRC "src/*.cpp" "src/*.hpp" "src/*.inl")
add_executable(${PROJECT_NAME} ${SRC})

set(CMAKE_CXX_FLAGS "-std=c++1z -Wall -Wextra -pedantic-errors")
set(CMAKE_CXX_COMPILER "clang++")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -g")
