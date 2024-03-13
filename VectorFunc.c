
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VectorStruct.h"
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
void* getVectorPtr(Vector* vec){
    if(vec!=NULL){
        return vec->elements;
    }
    return NULL;
}
FieldInfo* getVectorType(Vector* vec){
    if(vec!=NULL){
        return vec->typeInfo;
    }
    return NULL;
}



void SegFaultErrorCheck(Vector* vec,int index){
    if(getVectorSize(vec)<=index){
        printf("\n Out of Bound Error (Segmentation fault)\n");
        exit (11);
    }
}
int TypeCorrection(Vector* vec1 , Vector* vec2){
    if(getVectorType(vec1)==getVectorType(vec2)){
        return 1;
    }
    return 0;
}
int SizeCorrection(Vector* vec1 , Vector* vec2){
    if(getVectorSize(vec1)==getVectorSize(vec2)){
        return 1;
    }
    return 0;
}

void* getFromVector(Vector* vec,int index){
    SegFaultErrorCheck(vec,index);
    return  (void*)( (char*)getVectorPtr(vec) + (vec->typeInfo->element_size)*index );
}
void setToVector(Vector* vec, int index,void* input){
    SegFaultErrorCheck(vec,index);
    if(input==NULL){
        printf("\n NULL pointer exception in SET Function \n");
        //exit (1);
    }
    memcpy( (char*)getVectorPtr(vec) +index*vec->typeInfo->element_size ,input,vec->typeInfo->element_size);
}
void printVector(Vector* toPrint){
    for(int i=0 ; i<getVectorSize(toPrint);i++){
        printf("==========\n");
        toPrint->typeInfo->print(getFromVector(toPrint,i));
        printf("\n==========\n");
    }
}

void* scalarProduct(Vector* vec1 , Vector* vec2, void* result){
    if(!SizeCorrection(vec1,vec2) || !TypeCorrection(vec1,vec2)){
        printf("\n Error in Scalar Product : Incompatible Vectors\n NULL-pointer return");
        return NULL;
    }
    void* preresult=safeMalloc(vec1->typeInfo->element_size);
    vec1->typeInfo->zero(result);
    ObserverTrigger('N');
    for(int i=0;i<getVectorSize(vec1);i++){
        vec1->typeInfo->mult(getFromVector(vec1,i),getFromVector(vec2,i),preresult);
        ObserverTrigger('M');
        vec1->typeInfo->plus(preresult,result,result);
        ObserverTrigger('P');   
    }
    ObserverTrigger('X');
    free(preresult);
    return result;
}

Vector* createVector(FieldInfo* inputType,int size,void* elemFill){
    Vector* buf = (Vector*)safeMalloc(sizeof(Vector));
    buf->elements=(void*)safeMalloc(sizeof(char)*size*inputType->element_size);
    buf->size=size;
    buf->typeInfo=inputType;
    for(int i = 0;i<size;i++){
        memcpy( (char*)getVectorPtr(buf)+i*inputType->element_size , elemFill,inputType->element_size);
    }
    return buf;
}

Vector* plusVector(Vector* vec1 , Vector* vec2){
     if(!SizeCorrection(vec1,vec2) || !TypeCorrection(vec1,vec2)){
        printf("\n Error in Plus Vector : Incompatible Vectors\n NULL-pointer return");
        return NULL;
    }
    void* buf=safeMalloc(vec1->typeInfo->element_size);
    vec1->typeInfo->zero(buf);
    Vector* resultVec=createVector(vec1->typeInfo,getVectorSize(vec1),buf);
    for(int i =0 ; i <vec1->size;i++){
        vec1->typeInfo->plus(getFromVector(vec1,i),getFromVector(vec2,i),buf);
        ObserverTrigger('P');  
        setToVector(resultVec,i,buf);
    }
    ObserverTrigger('X');
    return resultVec;
}

void deleteVector(Vector** vec){
    if(*vec==NULL){
        printf("Already free pointer");
    }
    free(getVectorPtr(*vec));
    free(*vec);
    (*vec)=NULL;
}
