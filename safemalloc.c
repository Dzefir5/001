#include <stdio.h>
#include <malloc.h>
void* safeMalloc(int size){     //Просто функция для проверки корректности результата malloc-а
    void* buf = malloc(size);
    if(buf==NULL){
        printf("SafeMalloc Error : Return NULL ");
        exit(1);
    }
    return buf;
}