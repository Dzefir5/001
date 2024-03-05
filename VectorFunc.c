
#include <stdio.h>
#include <stdlib.h>
#include "VectorStruct.h"

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
