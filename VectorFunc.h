#pragma once

#include "VectorStruct.h"

void* getFromVector(Vector* vec, int index);
void setToVector(Vector* vec, int index, void* input);
void printVector(Vector* toPrint);
void* scalarProduct(Vector* vec1, Vector* vec2);
Vector* plusVector(Vector* vec1, Vector* vec2);

int getVectorSize(Vector* vec);
void* getVectorPtr(Vector* vec);

Vector* createVector(FieldInfo* inputType, int size, void* elemFill);
void deleteVector(Vector** vec);