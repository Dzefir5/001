#pragma once

typedef struct Observer{
    char* CommandList;
    int counter ;
    int TestLimit;
}TestObserver;

extern TestObserver* object;

TestObserver* ObserverTrigger(char signal);

int testIntSum(int* flag);
int testIntMult(int* flag);
int testIntNeutral(int* flag);

int testDoubleSum(int* flag);
int testDoubleMult(int* flag);
int testDoubleNeutral(int* flag);

int testFloatSum(int* flag);
int testFloatMult(int* flag);
int testFloatNeutral(int* flag);

int testComplexSum(int* flag);
int testComplexMult(int* flag);
int testComplexeNeutral(int* flag);
