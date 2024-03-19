#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CustomHeader.h"
#include "TestPrototype.h"

//clang Test.c TestPrototype.c VectorFunc.c VectorStruct.c TypeFunc.c TypeInfo.c safemalloc.c -Wall -Wextra -o test.exe

int main(){
    int flag = 0 ;
    testIntSum(&flag);
    testFloatSum(&flag);
    testDoubleSum(&flag);
    testComplexSum(&flag);

    testIntMult(&flag);
    testFloatMult(&flag);
    testDoubleMult(&flag);
    testComplexMult(&flag);

    testIntNeutral(&flag);
    testFloatNeutral(&flag);
    testDoubleNeutral(&flag);
    testComplexNeutral(&flag);

    testDotProduct();
    testVecSum();
    printf("Error count_%d_",flag);

    printf( "Test succeeded.\n" );
    return 0;
}