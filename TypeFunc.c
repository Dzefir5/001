#include <stdio.h>
#include <stdlib.h>
#include "ComplexStruct.h"

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

void* PlusFloat(void* a, void* b ){
    float* c=(float*)malloc(sizeof(float));
    *c = *((int*)a)+*((int*)b);
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