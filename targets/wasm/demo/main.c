#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

extern int codon_main(int argc, char *argv[]);

// If the user's `main` function expects arguments, the compiler will rename
// it to `__main_argc_argv`
// see the comment at https://github.com/WebAssembly/wasi-libc/tree/main/libc-bottom-half/sources/__main_void.c
// so this function will not conflict with the codon's `main` function
// The actual starting point is `_start` which resides in https://github.com/WebAssembly/wasi-libc/tree/main/libc-bottom-half/crt/crt1-command.c."
int main(int argc, char *argv[]) {
    return codon_main(argc, argv);
}
