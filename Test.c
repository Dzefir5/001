#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CustomHeader.h"
#include "TestPrototype.h"

int main(){
    ObserverTrigger('0');

    int n = 10;
    int example = 0; 
	Vector* vec1 = createVector(INT_INFO(), n, &example);
	Vector* vec2 = createVector(INT_INFO(), n, &example);
    Vector* result = plusVector(vec1, vec1);
    int* c = malloc(sizeof(int));
    scalarProduct(vec1,vec2,(void*)c);


    deleteVector(&vec1);
	deleteVector(&vec2);
	deleteVector(&result);
    for(int i =0; ObserverTrigger('0')->CommandList[i] != '0';i++){
        printf("_( %c )_\n",ObserverTrigger('0')->CommandList[i]);
    }
    return 0;
}