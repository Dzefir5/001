#pragma once

#include "TypeInfo.h"

//скрыть определение структуры , вынести методы по вне / или vtable(скорее первое)

typedef struct Vector {
    int size;
    void* elements;
    FieldInfo* typeInfo; 
} Vector;
