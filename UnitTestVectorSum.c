#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CustomHeader.h"
#include "UnitTestScalarProd.h"
#include "TypeFunc.h"

float FloatEps = 1e-6;
double DoubleEps = 1e-15;

void testSumInt()
{
	int n = 10;
    int example = 0; 
	Vector* vec1 = create_Vector(INT_INFO(), n, &example);
	Vector* vec2 = create_Vector(INT_INFO(), n, &example);
	int* testVec = (int*)malloc(n * sizeof(int));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int a = (rand() - rand())%1000;
        vec1->set(vec1, i, &a);
		int b = (rand() - rand())%1000;
		vec2->set(vec2, i, &b);

		testVec[i] = a+b;
	}

	Vector* result = PlusVector(vec1, vec2);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %3d == %3d - ",testVec[i],*((int*)(result->get(result,i))) );
        if(testVec[i]==*((int*)(result->get(result,i)))){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	delete_Vector(&vec1);
	delete_Vector(&vec2);
	delete_Vector(&result);
}

void testSumFloat()
{
	float FloatEps = 1e-6;
	int n = 10;
    float example = 0.0f; 
	Vector* vec1 = create_Vector(FLOAT_INFO(), n, &example);
	Vector* vec2 = create_Vector(FLOAT_INFO(), n, &example);
	float* testVec = (float*)malloc(n * sizeof(float));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		float a = randFloat(0.0f,123.01432f);
        vec1->set(vec1, i, &a);
		float b = randFloat(0.0f,240.62147f);
		vec2->set(vec2, i, &b);
		testVec[i] = a+b;
	}

	Vector* result = PlusVector(vec1, vec2);
	//result->printVec(result);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %10.10f == %10.10f - ",testVec[i],*((float*)(result->get(result,i))) );
        if(CompareFloat( (void*)(testVec+i),(result->get(result,i)),FloatEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	delete_Vector(&vec1);
	delete_Vector(&vec2);
	delete_Vector(&result);
}

void testSumDouble()
{
	double DoubleEps = 1e-15;
	int n = 10;
    double example = 0.0; 
	Vector* vec1 = create_Vector(DOUBLE_INFO(), n, &example);
	Vector* vec2 = create_Vector(DOUBLE_INFO(), n, &example);
	double* testVec = (double*)malloc(n * sizeof(double));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		double a = randDouble(0.0,123.01432);
        vec1->set(vec1, i, &a);
		double b = randDouble(0.0,240.62147);
		vec2->set(vec2, i, &b);

		testVec[i] = a+b;
	}

	Vector* result = PlusVector(vec1, vec2);
	//result->printVec(result);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %10.16lf == %10.16lf - ",testVec[i],*((double*)(result->get(result,i))) );
        if(CompareDouble( (void*)(testVec+i),(result->get(result,i)),DoubleEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	delete_Vector(&vec1);
	delete_Vector(&vec2);
	delete_Vector(&result);
}


void testSumComplex()
{
	double DoubleEps = 1e-15;
	int n = 10;
    Complex example = {0.0,0.0}; 
	Vector* vec1 = create_Vector(COMPLEX_INFO(), n, &example);
	Vector* vec2 = create_Vector(COMPLEX_INFO(), n, &example);
	Complex* testVec = (Complex*)malloc(n * sizeof(Complex));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		double ax =randDouble(52.0131,1123.0);
		double ay =randDouble(53.02414,1424.02131);
		Complex a = {ax,ay};
        vec1->set(vec1, i, (void*)&a);
		double bx =randDouble(31.55420,1875.04114);
		double by =randDouble(38.310,1123.1314);
		Complex b = {bx,by};
		vec2->set(vec2, i, (void*)&b);

		testVec[i].x+= a.x + b.x;
		testVec[i].y+= a.y + b.y;
	}

	Vector* result = PlusVector(vec1, vec2);
	result->printVec(result);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %lf+i*( %lf ) == %lf+i*( %lf )  - ",testVec[i].x,testVec[i].y,((Complex*)(result->get(result,i)))->x ,((Complex*)(result->get(result,i)))->y );
        if(CompareComplex( (void*)(testVec+i),(result->get(result,i)),DoubleEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	delete_Vector(&vec1);
	delete_Vector(&vec2);
	delete_Vector(&result);
}





