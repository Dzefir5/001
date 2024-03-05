#pragma once

typedef struct FieldInfo{
    int element_size;
    void* (*plus)(void* a, void* b );
    void* (*prod)(void* a, void* b );
    void* (*zero)();
    void  (*print)(void* a);
} FieldInfo;

FieldInfo* INT_INFO();
FieldInfo* FLOAT_INFO();
FieldInfo* DOUBLE_INFO();
FieldInfo* COMPLEX_INFO();
