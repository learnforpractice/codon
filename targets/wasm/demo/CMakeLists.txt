cmake_minimum_required(VERSION 3.16.3)

add_executable(demo main.c hello.codon)
set_target_properties(
    demo
    PROPERTIES 
    OUTPUT_NAME "demo"
    SUFFIX ".wasm"
)

target_compile_options(demo PRIVATE --sysroot=${WASI_SDK_PREFIX}/share/wasi-sysroot --target=wasm32-wasi)

set(CMAKE_CXX_FLAGS "-v ${CMAKE_CXX_FLAGS} -fno-exceptions -std=c++17")

add_custom_target( hello.o ALL
    COMMAND codon build --release --march=wasm32 --obj -o ${CMAKE_CURRENT_BINARY_DIR}/hello.o ${CMAKE_CURRENT_SOURCE_DIR}/hello.codon
    DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/hello.codon
    COMMENT "Generating hello.o")

target_link_libraries(demo PRIVATE ${CMAKE_CURRENT_BINARY_DIR}/hello.o codonrt)
add_dependencies(demo hello.o)
