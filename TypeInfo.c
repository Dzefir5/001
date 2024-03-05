

#include <stdio.h>
#include <stdlib.h>
#include "TypeFunc.h"
#include "TypeInfo.h"

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