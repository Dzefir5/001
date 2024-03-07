#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "CustomHeader.h"




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


void testScalarProdInt()
{	
	int n = 100;
    int example = 0; 
    Vector* vec1 = create_Vector(INT_INFO(), n, &example);
	Vector* vec2 = create_Vector(INT_INFO(), n, &example);
	int testScalProd = 0;
	srand(time(0));
	for (int i = 0; i < n; i++)
	{
		int a = (rand() - rand())%1000;
        vec1->set(vec1, i, &a);
		int b = (rand() - rand())%1000;
		vec2->set(vec2, i, &b);

		testScalProd+= a*b;
		
	}

	int* result = (int*)ScalarProduct(vec1, vec2);
	printf(" %d == %d - ",testScalProd,*result );
    if(testScalProd==*result){
            printf("TRUE");
    }else{
            printf("FALSE");
    }
    printf("\n");

	delete_Vector(&vec1);
	delete_Vector(&vec2);
}

void testScalarProdFloat()
{
	float FloatEps = 1e-6;
	int n = 10;
    float example = 0.0f; 
    Vector* vec1 = create_Vector(FLOAT_INFO(), n, &example);
	Vector* vec2 = create_Vector(FLOAT_INFO(), n, &example);
	float testScalProd = 0.0f;

	for (int i = 0; i < n; i++)
	{
		float a = randFloat(0.0f,123.01432f);
        vec1->set(vec1, i, &a);
		float b = randFloat(0.0f,240.62147f);
		vec2->set(vec2, i, &b);

		testScalProd+= a*b;
	}
	//ec1->printVec(vec1);
	//vec2->printVec(vec2);
	float* result = (float*)ScalarProduct(vec1, vec2);
	printf(" %f == %f - ",testScalProd,*result );
    if(CompareFloat( (void*)&testScalProd,(void*)result,FloatEps)){
            printf("TRUE");
    }else{
            printf("FALSE");
    }
    printf("\n");

	delete_Vector(&vec1);
	delete_Vector(&vec2);
}

void testScalarProdDouble()
{
	double DoubleEps = 1e-15;
	int n = 10;
    double example = 0.0; 
    Vector* vec1 = create_Vector(DOUBLE_INFO(), n, &example);
	Vector* vec2 = create_Vector(DOUBLE_INFO(), n, &example);
	double testScalProd = 0;

	for (int i = 0; i < n; i++)
	{
		double a = randDouble(0.0,1123.0);
        vec1->set(vec1, i, &a);
		double b = randDouble(0.0,113.0);
		vec2->set(vec2, i, &b);

		testScalProd+= a*b;
	}

	double* result = (double*)ScalarProduct(vec1, vec2);
	printf(" %lf == %lf - ",testScalProd,*result );
    if(CompareDouble( (void*)&testScalProd,(void*)result,DoubleEps)){
            printf("TRUE");
    }else{
            printf("FALSE");
    }
    printf("\n");

	delete_Vector(&vec1);
	delete_Vector(&vec2);
}

void testScalarProdComplex()
{
	double DoubleEps = 1e-15;
	int n = 10;
    Complex example = {0.0,0.0}; 
    Vector* vec1 = create_Vector(COMPLEX_INFO(), n, &example);
	Vector* vec2 = create_Vector(COMPLEX_INFO(), n, &example);
	Complex testScalProd = {0.0,0.0};

	for (int i = 0; i < n; i++)
	{
		double ax = randDouble(52.0131,1123.0);
		double ay = randDouble(53.02414,1424.02131);
		Complex a = {ax,ay};
        vec1->set(vec1, i, (void*)&a);
		double bx = randDouble(31.55420,1875.04114);
		double by = randDouble(38.310,1123.1314);
		Complex b = {bx,by};
		vec2->set(vec2, i, (void*)&b);

		testScalProd.x+= a.x*b.x - a.y * b.y;
		testScalProd.y+= a.x*b.y + a.y * b.x;
	}

	Complex* result = (Complex*)ScalarProduct(vec1, vec2);
	printf(" %lf+i*( %lf ) == %lf+i*( %lf )  - ",testScalProd.x,testScalProd.y,(*result).x,(*result).y );
    if(CompareComplex( (void*)&testScalProd,(void*)result,DoubleEps)){
            printf("TRUE");
    }else{
            printf("FALSE");
    }
    printf("\n");

	delete_Vector(&vec1);
	delete_Vector(&vec2);
}