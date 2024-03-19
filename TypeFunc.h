#pragma once

#include "ComplexStruct.h"
#include "TestPrototype.h"


void PlusComplex(void* a, void* b, void* c );
void ProdComplex(void* a, void* b, void* c );
void PrintComplex(void* a);
void NeuntralComplex(void* c);

void PlusInt(void* a, void* b, void* c );
void ProdInt(void* a, void* b, void* c );
void PrintInt(void* a);
void NeuntralInt(void* c);

void PlusFloat(void* a, void* b , void* c);
void ProdFloat(void* a, void* b, void* c);
void PrintFloat(void* a);
void NeuntralFloat(void* c);

void PlusDouble(void* a, void* b, void* c );
void ProdDouble(void* a, void* b, void* c );
void PrintDouble(void* a);
void NeuntralDouble(void* c);

void testOperation(const char *insymbol , Node* left, Node* right , Node* result);
void PlusTest(void* a, void* b, void* c );
void ProdTest(void* a, void* b, void* c );
void PrintTest(void* a);
void NeuntralTest(void* c);

int CompareFloat(void* a , void* b , float eps);
int CompareDouble(void* a , void* b , double eps);
int CompareComplex(void* a , void* b ,double eps);

