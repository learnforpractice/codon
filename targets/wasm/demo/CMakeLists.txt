cmake_minimum_required(VERSION 3.16.3)

add_executable(demo main.c)
set_target_properties(
    demo
    PROPERTIES 
    OUTPUT_NAME "demo"
    SUFFIX ".wasm"
)

target_compile_options(demo PRIVATE --sysroot=${WASI_SDK_PREFIX}/share/wasi-sysroot --target=wasm32-wasi)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-exceptions -std=c++17")

message(STATUS ${LLVM_BUILD_DIR}/bin/llc)
add_custom_target( hello.o ALL
    COMMAND codon build --release -o ${CMAKE_CURRENT_BINARY_DIR}/hello.ll ${CMAKE_CURRENT_SOURCE_DIR}/hello.codon
    # COMMAND codon build -o ${CMAKE_CURRENT_BINARY_DIR}/hello.ll ${CMAKE_CURRENT_SOURCE_DIR}/hello.codon
    COMMAND ${LLVM_BUILD_DIR}/bin/llc -march=wasm32 -filetype=obj ${CMAKE_CURRENT_BINARY_DIR}/hello.ll -o ${CMAKE_CURRENT_BINARY_DIR}/hello.o
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/hello.codon
    COMMENT "Generating libhello2.so")

target_link_libraries(demo PRIVATE codonrt ${CMAKE_CURRENT_BINARY_DIR}/hello.o)
add_dependencies(demo hello.o)
