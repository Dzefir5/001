#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include "CustomHeader.h"

static float floatEps = 1e-6;		//взять из библиотек
static double doubleEps = 1e-15;

int randInt(int max,int min){
	return rand()%(max-min) + min; 
}
float randFloat(float max,float min){
	float scale = (float)rand() / (float)RAND_MAX;
	return min + scale * (max-min);
}
double randDouble(double max,double min){
	double scale = (double)rand() / (float)RAND_MAX;
	return min + scale * (max-min);
}

//сделать проверки на каждую операцию 

//Именно проверка порядка выполнения операций внутри вектора  - атомарные тесты



void testSumInt()
{
	int n = 10;
    int example = 0; 
	Vector* vec1 = createVector(INT_INFO(), n, &example);
	Vector* vec2 = createVector(INT_INFO(), n, &example);
	int* testVec = (int*)safeMalloc(n * sizeof(int));
	for (int i = 0; i < n; i++)
	{
		int a = (rand() - rand())%1000;
        setToVector(vec1, i, &a);
		int b = (rand() - rand())%1000;
		setToVector(vec2, i, &b);

		testVec[i] = a+b;
	}
	
	Vector* result = plusVector(vec1, vec2);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %3d == %3d - ",testVec[i],*((int*)(getFromVector(result,i))) );
        if(testVec[i]==*((int*)(getFromVector(result,i)))){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	deleteVector(&vec1);
	deleteVector(&vec2);
	deleteVector(&result);
}

void testSumFloat()
{
	int n = 10;
    float example = 0.0f; 
	Vector* vec1 = createVector(FLOAT_INFO(), n, &example);
	Vector* vec2 = createVector(FLOAT_INFO(), n, &example);
	float* testVec = (float*)safeMalloc(n * sizeof(float));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		float a = randFloat(0.0f,123.01432f);
        setToVector(vec1, i, &a);
		float b = randFloat(0.0f,240.62147f);
		setToVector(vec2, i, &b);
		testVec[i] = a+b;
	}

	Vector* result = plusVector(vec1, vec2);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %10.10f == %10.10f - ",testVec[i],*((float*)(getFromVector(result,i))) );
        if(CompareFloat( (void*)(testVec+i),(getFromVector(result,i)),floatEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	deleteVector(&vec1);
	deleteVector(&vec2);
	deleteVector(&result);
}

void testSumDouble()
{
	int n = 10;
    double example = 0.0; 
	Vector* vec1 = createVector(DOUBLE_INFO(), n, &example);
	Vector* vec2 = createVector(DOUBLE_INFO(), n, &example);
	double* testVec = (double*)safeMalloc(n * sizeof(double));
	if (testVec == NULL)
	{
		printf("memory ERROR\n");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		double a = randDouble(0.0,123.01432);
        setToVector(vec1, i, &a);
		double b = randDouble(0.0,240.62147);
		setToVector(vec2, i, &b);

		testVec[i] = a+b;
	}

	Vector* result = plusVector(vec1, vec2);
	//result->printVec(result);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf(" %10.16lf == %10.16lf - ",testVec[i],*((double*)(getFromVector(result,i))) );
        if(CompareDouble( (void*)(testVec+i),(getFromVector(result,i)),doubleEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	deleteVector(&vec1);
	deleteVector(&vec2);
	deleteVector(&result);
}


void testSumComplex()
{
	int n = 10;
    Complex example = {0.0,0.0}; 
	Vector* vec1 = createVector(COMPLEX_INFO(), n, &example);
	Vector* vec2 = createVector(COMPLEX_INFO(), n, &example);
	Complex* testVec = (Complex*)safeMalloc(n * sizeof(Complex));
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
        setToVector(vec1, i, (void*)&a);
		double bx =randDouble(31.55420,1875.04114);
		double by =randDouble(38.310,1123.1314);
		Complex b = {bx,by};
		setToVector(vec2, i, (void*)&b);

		testVec[i].x+= a.x + b.x;
		testVec[i].y+= a.y + b.y;
	}

	Vector* result = plusVector(vec1, vec2);
	//result->printVec(result);
	printf("\n");
	for (int i = 0; i < n; i++)
	{   
		printf("%lf+i*(%lf) == %lf+i*( %lf )  - ",testVec[i].x,testVec[i].y,((Complex*)(getFromVector(result,i)))->x ,((Complex*)(getFromVector(result,i)))->y );
        if(CompareComplex( (void*)(testVec+i),(getFromVector(result,i)),doubleEps)){
            printf("TRUE");
        }else{
            printf("FALSE");
        }
        printf("\n");
	}
	deleteVector(&vec1);
	deleteVector(&vec2);
	deleteVector(&result);
}





