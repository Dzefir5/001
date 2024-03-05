#pragma once

#include "TypeInfo.h"

typedef struct Vector {
    int size;
    void* elements;

    FieldInfo* typeInfo;
    void* (*get)(struct Vector* vec,int index);
    void (*set)(struct Vector* vec,int index,void* input);
    struct Vector* (*plusVec)(struct Vector* v1,struct Vector* v2);
    void* (*scalProd)(struct Vector* v1,struct Vector* v2);
    void (*printVec)();
    
} Vector;
