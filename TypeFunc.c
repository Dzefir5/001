#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "safemalloc.h"
#include "ComplexStruct.h"
#include "TestPrototype.h"


    //Функции операций над типом Float
void plusFloat(void* a, void* b, void* c){
    assert(a && b && c );
    *(float*)c = *((float*)a)+*((float*)b);
}
void prodFloat(void* a, void* b, void* c){
    assert(a && b && c );
    *(float*)c = (*((float*)a)) * ( *((float*)b) );
}
void printFloat(void* a){
    assert(a);
    printf("%f",(*(float*)a));
}
void neuntralFloat(void* c){
    assert(c);
    *(float*)c=0.0f;
}
//Дополнительная функция сравнения обьектов типа Float - c погрешность eps
int compareFloat(void* a , void* b , float eps){
    assert(a && b);
    if(a==NULL || b==NULL){
        printf("NULL pointer argument");
        return 0 ;
    }
    return fabs( *(float*)a - *(float*)b ) < eps;
}

 //Функции операций над типом Double

void plusDouble(void* a, void* b, void* c){
    assert(a && b && c );
    *(double*)c = *((double*)a)+*((double*)b);
}
void prodDouble(void* a, void* b, void* c ){
    assert(a && b && c );
    *(double*)c = (*((double*)a)) * ( *((double*)b) );
}
void printDouble(void* a){
    assert(a);
    printf("%lf",(*(double*)a));
}
void neuntralDouble(void* c){
    assert(c);
    *(double*)c=0.0;
}

//Дополнительная функция сравнения обьектов типа Double - c погрешность eps
int compareDouble(void* a , void* b , double eps){
    assert(a && b);
    if(a==NULL || b==NULL){
        printf("NULL pointer argument");
        return 0 ;
    }
    return fabs( *(double*)a - *(double*)b ) < eps;
}


 //Функции операций над типом Complex

void plusComplex(void* a, void* b,void* c ){
    assert(a && b && c );
    ((Complex*)c)->x=((Complex*)a)->x + ((Complex*)b)->x;
    ((Complex*)c)->y=((Complex*)a)->y + ((Complex*)b)->y;
}
void prodComplex(void* a, void* b,void* c  ){
     assert(a && b && c );
    ((Complex*)c)->x=((Complex*)a)->x * ((Complex*)b)->x - ((Complex*)a)->y * ((Complex*)b)->y;
    ((Complex*)c)->y=((Complex*)a)->x * ((Complex*)b)->y + ((Complex*)a)->y * ((Complex*)b)->x;
}
void printComplex(void* a){
    assert(a);
    printf("%lf__%lf*i",((Complex*)a)->x,((Complex*)a)->y);
}
void neuntralComplex(void* c ){
    assert(c);
    ((Complex*)c)->x=0.0;
    ((Complex*)c)->y=0.0;
}

//Дополнительная функция сравнения обьектов типа Complex - c погрешность eps
int compareComplex(void* a , void* b ,double eps){
    assert(a && b);
    return compareDouble(a,b,eps ) && compareDouble( (void*)( (double*)a+1 ) , (void*)( (double*)b+1 ) ,eps  );
}


 //Функции операций над типом Int
void plusInt(void* a, void* b, void* c){
    assert(a && b && c );
    *(int*)c = (*((int*)a))+(*((int*)b));
}
void prodInt(void* a, void* b, void* c ){
    assert(a && b && c );
    *(int*)c = (*((int*)a)) * ( *((int*)b) );
}
void printInt(void* a){
    assert(a);
    printf("%d",(*(int*)a));
}
void neuntralInt(void* c){
    assert(c);
    *(int*)c=0;
}

static const char *CROSS = "*";
static const char *PLUS = "+";
static const char *ZERO = "0";

void testOperation(const char *insymbol , Node* left, Node* right , Node* result){
    result->leftNode = newNodeCopy( left );
	result->rightNode = newNodeCopy( right );
    result->symbol = strcpy((char*)safeMalloc(sizeof(char)*strlen(insymbol)) , insymbol);
}

void plusTest(void* a, void* b, void* c){
    assert(a && b && c);
    testOperation(PLUS,(Node*)a,(Node*)b,(Node*)c);
}
void prodTest(void* a, void* b, void* c ){
    assert(a && b && c);
    testOperation(CROSS,(Node*)a,(Node*)b,(Node*)c);
}
void printTest(void* a){
    assert(a);
    printf("_%s_",((Node*)a)->symbol);
}
void neuntralTest(void* c){
    assert(c);
    ((Node*)c)->symbol=ZERO;
    ((Node*)c)->leftNode = NULL;
	((Node*)c)->rightNode = NULL;
}

