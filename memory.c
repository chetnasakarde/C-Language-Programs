// File: mempool.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define POOL_SIZE 1024
char pool[POOL_SIZE];
int offset = 0;

void* mp_alloc(size_t size) {
    if (offset + size > POOL_SIZE) return NULL;
    void* ptr = pool + offset;
    offset += size;
    return ptr;
}

void mp_reset() { offset = 0; }

int main() {
    char* str = (char*)mp_alloc(20);
    strcpy(str, "Hacktoberfest!");
    printf("%s\n", str);
    mp_reset();
    return 0;
}
