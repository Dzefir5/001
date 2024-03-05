#include <stdio.h>
#include <stdlib.h>
#include "CustomHeader.h"

void testScalarProdInt()
{
	int n = 10000;
    int example = 0; 
    Vector* vec1 = create_Vector(INT_INFO, n, &example);
	Vector* vec2 = create_Vector(INT_INFO, n, &example);
	int testScalProd = 0;

	for (int i = 0; i < n; i++)
	{
		int a = rand() - rand();
        vec1->set(vec1, i, &a);
		int b = rand() - rand();
		vec2->set(vec2, i, &b);

		testScalProd+= a*b;
	}

	int* result = ScalarProduct(vec1, vec2);
	printf(" %d == %d - ",testScalProd,*result );
    if(testScalProd==*result){
            printf("TRUE");
    }else{
            printf("FALSE");
    }
    printf("\n");

	delete(vec1);
	delete(vec2);
	delete(result);
}
