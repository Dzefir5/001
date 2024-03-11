#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "ComplexStruct.h"


    //Функции операций над типом Float
void* PlusFloat(void* a, void* b ){
    float* c=(float*)malloc(sizeof(float));
    *c = *((float*)a)+*((float*)b);
    return (void*)c;
}
void* ProdFloat(void* a, void* b ){
    float* c=(float*)malloc(sizeof(float));
    *c = (*((float*)a)) * ( *((float*)b) );
    return (void*)c;
}
void PrintFloat(void* a){
    printf("%f",(*(float*)a));
}
void* NeuntralFloat(){
    float* c = (float*)malloc(sizeof(float));
    *c=0.0f;
    return (void*)c;
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

void* PlusDouble(void* a, void* b ){
    double* c=(double*)malloc(sizeof(double));
    *c = *((double*)a)+*((double*)b);
    return (void*)c;
}
void* ProdDouble(void* a, void* b ){
    double* c=(double*)malloc(sizeof(double));
    *c = (*((double*)a)) * ( *((double*)b) );
    return (void*)c;
}
void PrintDouble(void* a){
    printf("%lf",(*(double*)a));
}
void* NeuntralDouble(){
    double* c = (double*)malloc(sizeof(double));
    *c=0.0;
    return (void*)c;
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

void* PlusComplex(void* a, void* b ){
    Complex* c=(Complex*)malloc(sizeof(Complex));
    c->x=((Complex*)a)->x + ((Complex*)b)->x;
    c->y=((Complex*)a)->y + ((Complex*)b)->y;
    return (void*)c;
}
void* ProdComplex(void* a, void* b ){
    Complex* c=(Complex*)malloc(sizeof(Complex));
    c->x=((Complex*)a)->x * ((Complex*)b)->x - ((Complex*)a)->y * ((Complex*)b)->y;
    c->y=((Complex*)a)->x * ((Complex*)b)->y + ((Complex*)a)->y * ((Complex*)b)->x;
    return (void*)c;
}
void PrintComplex(void* a){
    printf("%lf__%lf*i",((Complex*)a)->x,((Complex*)a)->y);
}
void* NeuntralComplex(){
    Complex* c=(Complex*)malloc(sizeof(Complex));
    c->x=0.0;
    c->y=0.0;
    return (void*)c;
}

//Дополнительная функция сравнения обьектов типа Complex - c погрешность eps
int CompareComplex(void* a , void* b ,double eps){
    return CompareDouble(a,b,eps ) && CompareDouble( (void*)( (double*)a+1 ) , (void*)( (double*)b+1 ) ,eps  );
}


 //Функции операций над типом Int
void* PlusInt(void* a, void* b ){
    int* c=(int*)malloc(sizeof(int));
    *c = (*((int*)a))+(*((int*)b));
    return (void*)c;
}
void* ProdInt(void* a, void* b ){
    int* c=(int*)malloc(sizeof(int));
    *c = (*((int*)a)) * ( *((int*)b) );
    return (void*)c;
}
void PrintInt(void* a){
    printf("%d",(*(int*)a));
}

void* NeuntralInt(){
    int* c = (int*)malloc(sizeof(int));
    *c=0;
    return (void*)c;
}