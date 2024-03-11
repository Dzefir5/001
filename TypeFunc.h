#pragma once

#include "ComplexStruct.h"



void* PlusComplex(void* a, void* b );
void* ProdComplex(void* a, void* b );
void  PrintComplex(void* a);
void* NeuntralComplex();

void* PlusInt(void* a, void* b );
void* ProdInt(void* a, void* b );
void PrintInt(void* a);
void* NeuntralInt();

void* PlusFloat(void* a, void* b );
void* ProdFloat(void* a, void* b );
void PrintFloat(void* a);
void* NeuntralFloat();

void* PlusDouble(void* a, void* b );
void* ProdDouble(void* a, void* b );
void PrintDouble(void* a);
void* NeuntralDouble();


int CompareFloat(void* a , void* b , float eps);
int CompareDouble(void* a , void* b , double eps);
int CompareComplex(void* a , void* b ,double eps);

