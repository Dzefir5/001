#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "ComplexStruct.h"
#include "TypeInfo.h"

/*typedef struct {
    double x;
    double y;
} Complex;

typedef struct {
    int element_size;
    void* (*plus)(void* a, void* b );
    void* (*prod)(void* a, void* b );
    void* (*zero)();
    void  (*print)(void* a);
} FieldInfo;

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

FieldInfo* COMPLEX_INFO(){
    static FieldInfo* ComplexInfo=NULL;
    if(ComplexInfo!=NULL){
        return ComplexInfo;
    }
    ComplexInfo=(FieldInfo*)malloc(sizeof(FieldInfo));
    ComplexInfo->plus=&PlusComplex;
    ComplexInfo->prod=&ProdComplex;
    ComplexInfo->print=&PrintComplex;
    ComplexInfo->zero=&NeuntralComplex;
    ComplexInfo->element_size=sizeof(Complex);
    return ComplexInfo;
}

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
FieldInfo* INT_INFO(){
    static FieldInfo* IntInfo=NULL;
    if(IntInfo!=NULL){
        return IntInfo;
    }
    IntInfo=(FieldInfo*)malloc(sizeof(FieldInfo));
    IntInfo->plus=&PlusInt;
    IntInfo->prod=&ProdInt;
    IntInfo->print=&PrintInt;
    IntInfo->zero=&NeuntralInt;
    IntInfo->element_size=sizeof(int);
    return IntInfo;
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
FieldInfo* FLOAT_INFO(){
    static FieldInfo* FloatInfo=NULL;
    if(FloatInfo!=NULL){
        return FloatInfo;
    }
    FloatInfo=(FieldInfo*)malloc(sizeof(FieldInfo));
    FloatInfo->plus=&PlusFloat;
    FloatInfo->prod=&ProdFloat;
    FloatInfo->print=&PrintFloat;
    FloatInfo->zero=&NeuntralFloat;
    FloatInfo->element_size=sizeof(float);
    return FloatInfo;
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
FieldInfo* DOUBLE_INFO(){
    static FieldInfo* DoubleInfo=NULL;
    if(DoubleInfo!=NULL){
        return DoubleInfo;
    }
    DoubleInfo=(FieldInfo*)malloc(sizeof(FieldInfo));
    DoubleInfo->plus=&PlusDouble;
    DoubleInfo->prod=&ProdDouble;
    DoubleInfo->print=&PrintDouble;
    DoubleInfo->zero=&NeuntralDouble;
    DoubleInfo->element_size=sizeof(double);
    return DoubleInfo;
}





typedef struct Vector {
    int size;
    void* elements;

    FieldInfo* typeInfo;
    void* (*get)(struct Vector* vec,int index);
    void (*set)(struct Vector* vec,int index,void* input);
    struct Vector* (*plusVec)(struct Vector* v1,struct Vector* v2);
    void* (*scalProd)(struct Vector* v1,struct Vector* v2);
    void (*printVec)();
    
} Vector;

void* getFromVector(Vector* vec,int index){
    return  (void*)( (char*)vec->elements + (vec->typeInfo->element_size)*index );
}
void setToVector(Vector* vec, int index,void* input){
    memcpy( (char*)( vec->elements) +index*vec->typeInfo->element_size ,input,vec->typeInfo->element_size);
}
void PrintVector(Vector* toPrint){
    for(int i=0 ; i<(toPrint->size);i++){
        printf("_________\n");
        toPrint->typeInfo->print(toPrint->get(toPrint,i));
        printf("\n__________\n");
    }
}

void* ScalarProduct(Vector* vec1 , Vector* vec2){
    if(vec1->size!=vec2->size || vec1->typeInfo!=vec2->typeInfo){
        //ERROR
    }
    void* result=NULL;
    void* buffer=NULL;
    for(int i=0;i<vec1->size;i++){
        void* preresult=vec1->typeInfo->prod(vec1->get(vec1,i),vec2->get(vec2,i));
        if(i==0){
            buffer = vec1->typeInfo->zero();
        }else{
            buffer = result;
        }
        result = vec1->typeInfo->plus(preresult,buffer);
        free(preresult);
        free(buffer);
    }
    return result;
}




Vector* create_Vector(FieldInfo* inputType,int size,void* elemFill){
    Vector* buf = (Vector*)malloc(sizeof(Vector));
    buf->elements=(void*)malloc(sizeof(char)*size*inputType->element_size);
    buf->size=size;
    buf->typeInfo=inputType;
    buf->get=&getFromVector;
    buf->printVec=&PrintVector;
    buf->set=&setToVector;
    for(int i = 0;i<size;i++){
        memcpy( (char*)(buf->elements)+i*inputType->element_size , elemFill,inputType->element_size);
    }
    return buf;
}

Vector* PlusVector(Vector* vec1 , Vector* vec2){
    if(vec1->size!=vec2->size || vec1->typeInfo!=vec2->typeInfo){
        //ERROR
    }
    void* buf=vec1->typeInfo->zero();
    Vector* resultVec=create_Vector(vec1->typeInfo,vec1->size,buf);
    free(buf);
    for(int i =0 ; i <vec1->size;i++){
        buf=vec1->typeInfo->plus(vec1->get(vec1,i),vec2->get(vec2,i));
        resultVec->set(resultVec,i,buf);
        free(buf);
    }
    return resultVec;

}

void delete_Vector(Vector* vec){
    free(vec->elements);
    free(vec->typeInfo);
}
*/
int main(){
    int a=2;
    int b =3;
    Complex cmp1 = {1.5,3.5};
    Vector* myvec1 =  create_Vector(COMPLEX_INFO(),3,(void*)&cmp1);
    Vector* myvec2 =  create_Vector(INT_INFO(),3,(void*)&a);
    myvec1->printVec(myvec1);
    return 0;
}