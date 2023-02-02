cmake_minimum_required(VERSION 3.16.3)

add_library( codonrt exc.cpp lib.cpp ../../../build/_deps/fmt-src/src/format.cc)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -std=c++17")

target_compile_options(codonrt PRIVATE --sysroot=${WASI_SDK_PREFIX}/share/wasi-sysroot --target=wasm32-wasi)
# target_link_libraries(codonrt PRIVATE gc)
target_include_directories(codonrt PRIVATE ../../../build/_deps/fmt-src/include)
