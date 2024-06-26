#pragma once

typedef struct FieldInfo{
    int element_size;
    void (*plus)(void* a, void* b,void* c);
    void (*mult)(void* a, void* b,void* c); 
    void (*zero)(void* c);
    void  (*print)(void* a);
} FieldInfo;

//в идеальном виде : всё в раздельные .h .c файлы под екаждый тип
FieldInfo* INT_INFO();
FieldInfo* FLOAT_INFO();
FieldInfo* DOUBLE_INFO();
FieldInfo* COMPLEX_INFO();
FieldInfo* TEST_INFO();
