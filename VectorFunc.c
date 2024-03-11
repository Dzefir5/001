
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "VectorStruct.h"
#include "safemalloc.h"

void SegFaultErrorCheck(Vector* vec,int index){
    if(vec->size<=index){
        printf("\n Out of Bound Error (Segmentation fault)\n");
        exit (11);
    }
}
int TypeCorrection(Vector* vec1 , Vector* vec2){
    if(vec1->typeInfo==vec2->typeInfo){
        return 1;
    }
    return 0;
}
int SizeCorrection(Vector* vec1 , Vector* vec2){
    if(vec1->size==vec2->size){
        return 1;
    }
    return 0;
}

void* getFromVector(Vector* vec,int index){
    SegFaultErrorCheck(vec,index);
    return  (void*)( (char*)vec->elements + (vec->typeInfo->element_size)*index );
}
void setToVector(Vector* vec, int index,void* input){
    SegFaultErrorCheck(vec,index);
    if(input==NULL){
        printf("\n NULL pointer exception in SET Function \n");
        //exit (1);
    }
    memcpy( (char*)( vec->elements) +index*vec->typeInfo->element_size ,input,vec->typeInfo->element_size);
}
void PrintVector(Vector* toPrint){
    for(int i=0 ; i<(toPrint->size);i++){
        printf("==========\n");
        toPrint->typeInfo->print(toPrint->get(toPrint,i));
        printf("\n==========\n");
    }
}

void* ScalarProduct(Vector* vec1 , Vector* vec2){
    if(!SizeCorrection(vec1,vec2) || !TypeCorrection(vec1,vec2)){
        printf("\n Error in Scalar Product : Incompatible Vectors\n NULL-pointer return");
        return NULL;
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
    Vector* buf = (Vector*)safeMalloc(sizeof(Vector));
    buf->elements=(void*)safeMalloc(sizeof(char)*size*inputType->element_size);
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
     if(!SizeCorrection(vec1,vec2) || !TypeCorrection(vec1,vec2)){
        printf("\n Error in Plus Vector : Incompatible Vectors\n NULL-pointer return");
        return NULL;
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

void delete_Vector(Vector** vec){
    if(*vec==NULL){
        printf("Already free pointer");
    }
    free((*vec)->elements);
    free(*vec);
    (*vec)=NULL;
    
}
