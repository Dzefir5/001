#pragma once

#include "VectorStruct.h" //скрыть , сделать через typedef

void* getFromVector(Vector* vec, int index);
void setToVector(Vector* vec, int index, void* input);
void PrintVector(Vector* toPrint);
void* ScalarProduct(Vector* vec1, Vector* vec2);
Vector* PlusVector(Vector* vec1, Vector* vec2);

Vector* create_Vector(FieldInfo* inputType, int size, void* elemFill);
void delete_Vector(Vector** vec);