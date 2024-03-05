#include "VectorStruct.h"

void* getFromVector(Vector* vec,int index);
void setToVector(Vector* vec, int index,void* input);
void PrintVector(Vector* toPrint);
void* ScalarProduct(Vector* vec1 , Vector* vec2);
Vector* PlusVector(Vector* vec1 , Vector* vec2);
void delete_Vector(Vector* vec);