#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CustomHeader.h"

void testSumInt()
{
	int n = 10000;
    int example = 0; 
	Vector* vec1 = create_Vector(INT_INFO, n, &example);
	Vector* vec2 = create_Vector(INT_INFO, n, &example);
	int* testVec = (int*)malloc(n * sizeof(int));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int a = rand() - rand();
        vec1->set(vec1, i, &a);
		int b = rand() - rand();
		vec2->set(vec2, i, &b);

		testVec[i] = a+b;
	}

	Vector* result = PlusVector(vec1, vec2);

	for (int i = 0; i < n; i++)
	{   
		printf(" %d == %d - ",testVec[i],*((int*)(result->get(result,i))) );
        if(testVec[i]==*((int*)(result->get(result,i)))){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	delete(vec1);
	delete(vec2);
	delete(result);
}
