# Building codon with WebAssembly Support

## Building LLVM

In the codon source directory, run the following command to build LLVM:
```bash
git clone --depth 1 -b codon https://github.com/exaloop/llvm-project
cmake -S llvm-project/llvm -B llvm-project/build -G Ninja \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_ENABLE_PROJECTS="clang;lld" \
    -DLLVM_INCLUDE_TESTS=OFF \
    -DLLVM_ENABLE_RTTI=ON \
    -DLLVM_ENABLE_ZLIB=OFF \
    -DLLVM_ENABLE_TERMINFO=OFF \
    -DLLVM_TARGETS_TO_BUILD=all
cmake --build llvm-project/build
```

## Building codon with the WebAssembly runtime

- Download the WebAssembly System Interface (WASI) SDK from https://github.com/WebAssembly/wasi-sdk/tags
- Run the following command to build codon with the WebAssembly runtime, adjust the directory paths accordingly:

```bash
export PATH=$(pwd)/build:$PATH
cmake -S . -B build -G Ninja \
    -DBUILD_WASM=TRUE \
    -DWASI_SDK_PREFIX=path/to/wasi-sdk \
    -DCMAKE_BUILD_TYPE=Release \
    -DLLVM_BUILD_DIR=path/to/llvm-project/build \
    -DLLVM_DIR=path/to/llvm-project/build/lib/cmake/llvm \
    -DCMAKE_C_COMPILER=clang \
    -DCMAKE_CXX_COMPILER=clang++

cmake --build build --config Release
```

## Running

```bash
wasmtime ./build/targets/wasm/demo/demo.wasm
```
