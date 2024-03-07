#include <stdio.h>
#include <malloc.h>
void* safeMalloc(int size){
    void* buf = malloc(size);
    if(buf==NULL){
        printf("SafeMalloc Error : Return NULL ");
    }
    return buf;
}