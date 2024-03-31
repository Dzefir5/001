#include <stdio.h>
#include "TestPrototype.h"

//clang Test.c TestPrototype.c VectorFunc.c TypeFunc.c TypeInfo.c safemalloc.c -Wall -Wextra -o test.exe

int main(){
    testIntSum();
    testFloatSum();
    testDoubleSum();
    testComplexSum();
    testIntMult();
    testFloatMult();
    testDoubleMult();
    testComplexMult();

    testIntNeutral();
    testFloatNeutral();
    testDoubleNeutral();
    testComplexNeutral();

    testDotProduct();
    testVecSum();

    printf( "Test succeeded.\n" );
    return 0;
}