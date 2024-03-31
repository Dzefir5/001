#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>

void* safeMalloc(size_t size){     //Просто функция для проверки корректности результата malloc-а
    void* buf = malloc(size);
    assert(buf!=NULL && "SafeMalloc Error ");
    return buf;
}