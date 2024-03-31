#pragma once

#include "ComplexStruct.h"
#include "TestPrototype.h"


void plusComplex(void* a, void* b, void* c );
void prodComplex(void* a, void* b, void* c );
void printComplex(void* a);
void neuntralComplex(void* c);

void plusInt(void* a, void* b, void* c );
void prodInt(void* a, void* b, void* c );
void printInt(void* a);
void neuntralInt(void* c);

void plusFloat(void* a, void* b , void* c);
void prodFloat(void* a, void* b, void* c);
void printFloat(void* a);
void neuntralFloat(void* c);

void plusDouble(void* a, void* b, void* c );
void prodDouble(void* a, void* b, void* c );
void printDouble(void* a);
void neuntralDouble(void* c);

void testOperation(const char *insymbol , Node* left, Node* right , Node* result);
void plusTest(void* a, void* b, void* c );
void prodTest(void* a, void* b, void* c );
void printTest(void* a);
void neuntralTest(void* c);

int compareFloat(void* a , void* b , float eps);
int compareDouble(void* a , void* b , double eps);
int compareComplex(void* a , void* b ,double eps);

