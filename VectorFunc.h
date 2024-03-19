#pragma once

#include "VectorStruct.h"
#include "TypeInfo.h"

void* getFromVector(Vector* vec, int index);
void setToVector(Vector* vec, int index, void* input);
void printVector(Vector* toPrint);
void* scalarProduct(Vector* vec1, Vector* vec2,void* result);
Vector* plusVector(Vector* vec1, Vector* vec2);

int getVectorSize(Vector* vec);
FieldInfo* getVectorType(Vector* vec);

Vector* createVector(FieldInfo* inputType, int size, void* elemFill);
void deleteVector(Vector** vec);

int isTypeEqual(Vector* vec1 , Vector* vec2);
int isSizeEqual(Vector* vec1 , Vector* vec2); 
