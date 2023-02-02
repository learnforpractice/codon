project(runtime-wasi)

cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# add_subdirectory(../../build/_deps/fmt-src fmt)
# add_subdirectory(../../build/_deps/bdwgc-src gc)

# add_subdirectory(bdwgc)

add_subdirectory(runtime-wasi)
add_subdirectory(demo)
