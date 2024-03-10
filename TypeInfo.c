

#include <stdio.h>
#include <stdlib.h>
#include "TypeFunc.h"
#include "TypeInfo.h"
#include "safemalloc.h"


FieldInfo* INT_INFO(){
    static FieldInfo* IntInfo=NULL;                     // Выделение статической памяти под указатель при запуске программы
    if(IntInfo!=NULL){                                  // Проверка на то инициализирован ли обьект
        return IntInfo;                                 // Возвращение указателя на обьект 
    }
    IntInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    IntInfo->plus=&PlusInt;                             //
    IntInfo->prod=&ProdInt;                             //
    IntInfo->print=&PrintInt;                           // Инициализация обьекта при его первом использовании
    IntInfo->zero=&NeuntralInt;                         //
    IntInfo->element_size=sizeof(int);                  //
    return IntInfo;                                     // Возвравщение указателя на обьект   P.S Указатели на обьекты информации разных типов различны и постоянны что позволяет реализовать сравнение типов через сравнение указателей
}

FieldInfo* COMPLEX_INFO(){
    static FieldInfo* ComplexInfo=NULL;  
    if(ComplexInfo!=NULL){
        return ComplexInfo;
    }
    ComplexInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    ComplexInfo->plus=&PlusComplex;
    ComplexInfo->prod=&ProdComplex;
    ComplexInfo->print=&PrintComplex;
    ComplexInfo->zero=&NeuntralComplex;
    ComplexInfo->element_size=sizeof(Complex);
    return ComplexInfo;
}

FieldInfo* FLOAT_INFO(){
    static FieldInfo* FloatInfo=NULL;
    if(FloatInfo!=NULL){
        return FloatInfo;
    }
    FloatInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
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
    DoubleInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    DoubleInfo->plus=&PlusDouble;
    DoubleInfo->prod=&ProdDouble;
    DoubleInfo->print=&PrintDouble;
    DoubleInfo->zero=&NeuntralDouble;
    DoubleInfo->element_size=sizeof(double);
    return DoubleInfo;
}