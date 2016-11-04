#include <stdio.h>
#include <stdint.h>
#include <stdarg.h>

void* dummy(int n_args, ...) {

    va_list valist;

    va_start(valist, n_args);    

    void* addr = 0, *curAddr;
    for (int i = 0; i < n_args; i++) {
        curAddr = va_arg(valist, void*);
        addr = (void *) ((uintptr_t)addr ^ (uintptr_t)curAddr);
    }

    va_end(valist);
    
    return addr;
}
