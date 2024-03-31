#include <stdio.h>
#include <stdlib.h>

#include "TypeFunc.h"
#include "TypeInfo.h"
#include "safemalloc.h"
#include "TestPrototype.h"

FieldInfo* INT_INFO(){
    static FieldInfo* IntInfo=NULL;                     // Выделение статической памяти под указатель при запуске программы
    if(IntInfo!=NULL){                                  // Проверка на то инициализирован ли обьект
        return IntInfo;                                 // Возвращение указателя на обьект 
    }
    IntInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    IntInfo->plus=&plusInt;                             //
    IntInfo->mult=&prodInt;                             //
    IntInfo->print=&printInt;                           // Инициализация обьекта при его первом использовании
    IntInfo->zero=&neuntralInt;                         //
    IntInfo->element_size=sizeof(int);                  //
    return IntInfo;                                     // Возвравщение указателя на обьект   
    //P.S Указатели на обьекты информации разных типов различны и постоянны что позволяет реализовать сравнение типов через сравнение указателей
}

FieldInfo* COMPLEX_INFO(){
    static FieldInfo* ComplexInfo=NULL;  
    if(ComplexInfo!=NULL){
        return ComplexInfo;
    }
    ComplexInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    ComplexInfo->plus=&plusComplex;
    ComplexInfo->mult=&prodComplex;
    ComplexInfo->print=&printComplex;
    ComplexInfo->zero=&neuntralComplex;
    ComplexInfo->element_size=sizeof(Complex);
    return ComplexInfo;
}

FieldInfo* FLOAT_INFO(){
    static FieldInfo* FloatInfo=NULL;
    if(FloatInfo!=NULL){
        return FloatInfo;
    }
    FloatInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    FloatInfo->plus=&plusFloat;
    FloatInfo->mult=&prodFloat;
    FloatInfo->print=&printFloat;
    FloatInfo->zero=&neuntralFloat;
    FloatInfo->element_size=sizeof(float);
    return FloatInfo;
}

FieldInfo* DOUBLE_INFO(){
    static FieldInfo* DoubleInfo=NULL;
    if(DoubleInfo!=NULL){
        return DoubleInfo;
    }
    DoubleInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    DoubleInfo->plus=&plusDouble;
    DoubleInfo->mult=&prodDouble;
    DoubleInfo->print=&printDouble;
    DoubleInfo->zero=&neuntralDouble;
    DoubleInfo->element_size=sizeof(double);
    return DoubleInfo;
}

FieldInfo* TEST_INFO(){
    static FieldInfo* TestInfo=NULL;
    if(TestInfo!=NULL){
        return TestInfo;
    }
    TestInfo=(FieldInfo*)safeMalloc(sizeof(FieldInfo));
    TestInfo->plus=&plusTest;
    TestInfo->mult=&prodTest;
    TestInfo->print=&printTest;
    TestInfo->zero=&neuntralTest;
    TestInfo->element_size=sizeof(Node);
    return TestInfo;
}