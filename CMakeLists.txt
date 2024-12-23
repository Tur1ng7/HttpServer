cmake_minimum_required(VERSION 3.10)

project(HttpServer VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(HttpServer ${SOURCES})

if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(HttpServer PRIVATE -Wall -Wextra -Wpedantic)
endif()

find_package(Threads REQUIRED)
target_link_libraries(HttpServer Threads::Threads)

set(CMAKE_BUILD_TYPE Debug)
