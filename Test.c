#include <stdio.h>

#include "TestPrototype.h"

//clang Test.c TestPrototype.c VectorFunc.c TypeFunc.c TypeInfo.c safemalloc.c -Wall -Wextra -o test.exe

int main(){
    testInt();
    testFloat();
    testDouble();
    testComplex();

    testDotProduct();
    testVecSum();

    printf( "Test succeeded.\n" );
    return 0;
}