#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ComplexStruct.h"
#include "TestPrototype.h"


    //Функции операций над типом Float
void PlusFloat(void* a, void* b, void* c){
    *(float*)c = *((float*)a)+*((float*)b);
}
void ProdFloat(void* a, void* b, void* c){
    *(float*)c = (*((float*)a)) * ( *((float*)b) );
}
void PrintFloat(void* a){
    printf("%f",(*(float*)a));
}
void NeuntralFloat(void* c){
    *(float*)c=0.0f;
}
//Дополнительная функция сравнения обьектов типа Float - c погрешность eps
int CompareFloat(void* a , void* b , float eps){
    if(a==NULL || b==NULL){
        printf("NULL pointer argument");
        return 0 ;
    }
    return fabs( *(float*)a - *(float*)b ) < eps;
}

 //Функции операций над типом Double

void PlusDouble(void* a, void* b, void* c){
    *(double*)c = *((double*)a)+*((double*)b);
}
void ProdDouble(void* a, void* b, void* c ){
    *(double*)c = (*((double*)a)) * ( *((double*)b) );
}
void PrintDouble(void* a){
    printf("%lf",(*(double*)a));
}
void NeuntralDouble(void* c){
    *(double*)c=0.0;
}

//Дополнительная функция сравнения обьектов типа Double - c погрешность eps
int CompareDouble(void* a , void* b , double eps){
    if(a==NULL || b==NULL){
        printf("NULL pointer argument");
        return 0 ;
    }
    return fabs( *(double*)a - *(double*)b ) < eps;
}


 //Функции операций над типом Complex

void PlusComplex(void* a, void* b,void* c ){
    ((Complex*)c)->x=((Complex*)a)->x + ((Complex*)b)->x;
    ((Complex*)c)->y=((Complex*)a)->y + ((Complex*)b)->y;
}
void ProdComplex(void* a, void* b,void* c  ){
    ((Complex*)c)->x=((Complex*)a)->x * ((Complex*)b)->x - ((Complex*)a)->y * ((Complex*)b)->y;
    ((Complex*)c)->y=((Complex*)a)->x * ((Complex*)b)->y + ((Complex*)a)->y * ((Complex*)b)->x;
}
void PrintComplex(void* a){
    printf("%lf__%lf*i",((Complex*)a)->x,((Complex*)a)->y);
}
void NeuntralComplex(void* c ){
    ((Complex*)c)->x=0.0;
    ((Complex*)c)->y=0.0;
}

//Дополнительная функция сравнения обьектов типа Complex - c погрешность eps
int CompareComplex(void* a , void* b ,double eps){
    return CompareDouble(a,b,eps ) && CompareDouble( (void*)( (double*)a+1 ) , (void*)( (double*)b+1 ) ,eps  );
}


 //Функции операций над типом Int
void PlusInt(void* a, void* b, void* c){
    *(int*)c = (*((int*)a))+(*((int*)b));
}
void ProdInt(void* a, void* b, void* c ){
    *(int*)c = (*((int*)a)) * ( *((int*)b) );
}
void PrintInt(void* a){
    printf("%d",(*(int*)a));
}
void NeuntralInt(void* c){
    *(int*)c=0;
}

static const char *X1 = "x1";
static const char *Y1 = "y1";
static const char *X2 = "x2";
static const char *Y2 = "y2";
static const char *X3 = "x3";
static const char *Y3 = "y3";
static const char *CROSS = "*";
static const char *PLUS = "+";
static const char *ZERO = "0";

void testOperation(const char *insymbol , Node* left, Node* right , Node* result){
    result->leftNode = newNodeCopy( left );
	result->rightNode = newNodeCopy( right );
    result->symbol = (char*)insymbol;
}

void PlusTest(void* a, void* b, void* c){
    testOperation(PLUS,(Node*)a,(Node*)b,(Node*)c);
}
void ProdTest(void* a, void* b, void* c ){
    testOperation(CROSS,(Node*)a,(Node*)b,(Node*)c);
}
void PrintTest(void* a){
    printf("_%s_",((Node*)a)->symbol);
}
void NeuntralTest(void* c){
    ((Node*)c)->symbol=ZERO;
    ((Node*)c)->leftNode = NULL;
	((Node*)c)->rightNode = NULL;
}

