cmake_minimum_required(VERSION 3.7)
project(OccultMathParser)

file(GLOB SOURCE_AND_HEADERS
    "src/*.hpp"
    "src/*.cpp"
    "include/*.hpp"
)

set(CMAKE_CXX_STANDARD 14)
include_directories("include/")

set(CMAKE_CXX_FLAGS "-Wall")
add_executable(occult_math_parser ${SOURCE_AND_HEADERS})
