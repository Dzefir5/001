#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
void* safeMalloc(size_t size){     //Просто функция для проверки корректности результата malloc-а
    void* buf = malloc(size);
    if(buf==NULL){
        printf("SafeMalloc Error : Return NULL "); //stderr
        exit(1);
    }
    return buf;
}