cmake_required_version(3.7)
project(OccultMathParser)

file(GLOB SOURCE_AND_HEADERS
    "src/*.hpp"
    "src/*.cpp"
    "include/*.hpp"
)

set(CMAKE_CXX_FLAGS "-Wall -std=c++14 -lstdc++")

add_executable(occult_math_parser ${SOURCE_AND_HEADERS})
