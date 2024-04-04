#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "safemalloc.h"
#include "TypeInfo.h"
#include "TestPrototype.h"

typedef struct Vector {
    int size;
    void* elements;
    FieldInfo* typeInfo; 
} Vector;

int getVectorSize(Vector* vec){
    if(vec!=NULL){
        return vec->size;
    }
    return 0;
}

FieldInfo* getVectorType(Vector* vec){
    if(vec!=NULL){
        return vec->typeInfo;
    }
    return NULL;
}



void outOfBoundErrorCheck(Vector* vec,int index){ //OutOFbOund
    if(getVectorSize(vec)<=index){
        printf("\n Out of Bound Error\n");
        exit (11);
    }
}
int isTypeEqual(Vector* vec1 , Vector* vec2){
    return getVectorType(vec1)==getVectorType(vec2);
}
int isSizeEqual(Vector* vec1 , Vector* vec2){
    return getVectorSize(vec1)==getVectorSize(vec2);
}

void* getFromVector(Vector* vec,int index){
    outOfBoundErrorCheck(vec,index);
    return  (void*)( (char*)vec->elements + (vec->typeInfo->element_size)*index );
}
void setToVector(Vector* vec, int index,void* input){
    outOfBoundErrorCheck(vec,index);
    if(input==NULL){
        printf("\n NULL pointer exception in SET Function \n");
        exit (1);
    }
    memcpy( (char*)vec->elements +index*vec->typeInfo->element_size ,input,vec->typeInfo->element_size);
}
void printVector(Vector* toPrint){
    for(int i=0 ; i<getVectorSize(toPrint);i++){
        printf("==========\n");
        toPrint->typeInfo->print(getFromVector(toPrint,i));
        printf("\n==========\n");
    }
}

void scalarProduct(Vector* vec1 , Vector* vec2, void* result){
    if(!isSizeEqual(vec1,vec2) || !isTypeEqual(vec1,vec2)){
        printf("\n Error in Scalar Product : Incompatible Vectors\n NULL-pointer return");
    }
    void* preresult1=safeMalloc(vec1->typeInfo->element_size);
    void* preresult2=safeMalloc(vec1->typeInfo->element_size);
    vec1->typeInfo->mult(getFromVector(vec1,0),getFromVector(vec2,0),preresult1);
    for(int i=1;i<getVectorSize(vec1);i++){
        vec1->typeInfo->mult(getFromVector(vec1,i),getFromVector(vec2,i),preresult2);
        vec1->typeInfo->plus(preresult1,preresult2,preresult1);   
    }
    memcpy( (void*)result,(void*)preresult1,vec1->typeInfo->element_size);
    free(preresult1);
    free(preresult2);
}

Vector* createVector(FieldInfo* inputType,int size,void* elemFill){
    Vector* buf = (Vector*)safeMalloc(sizeof(Vector));
    buf->elements=(void*)safeMalloc(sizeof(char)*size*inputType->element_size);
    buf->size=size;
    buf->typeInfo=inputType;
    for(int i = 0;i<size;i++){
        memcpy( (char*)buf->elements+i*inputType->element_size , elemFill,inputType->element_size);
    }
    return buf;
}

Vector* plusVector(Vector* vec1 , Vector* vec2){
     if(!isSizeEqual(vec1,vec2) || !isTypeEqual(vec1,vec2)){
        printf("\n Error in Plus Vector : Incompatible Vectors\n NULL-pointer return");
        return NULL;
    }
    void* buf=safeMalloc(vec1->typeInfo->element_size);
    vec1->typeInfo->zero(buf);
    Vector* resultVec=createVector(vec1->typeInfo,getVectorSize(vec1),buf);
    for(int i =0 ; i <vec1->size;i++){
        vec1->typeInfo->plus(getFromVector(vec1,i),getFromVector(vec2,i),buf); 
        setToVector(resultVec,i,buf);
    }
    return resultVec;
}

void deleteVector(Vector** vec){
    if(*vec==NULL){
        printf("Already free pointer");
    }
    free((*vec)->elements);
    free(*vec);
    (*vec)=NULL;
}
