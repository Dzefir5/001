#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "CustomHeader.h"

//обьявить обьект через extern отдельно

//assert что это ?


float floatEps = 1e-6;
double doubleEps = 1e-15;

TestObserver* object = NULL;

TestObserver* ObserverTrigger(char signal){
    if(signal=='0'&&object==NULL){
        object = (TestObserver*)safeMalloc(sizeof(TestObserver));
        object->counter=0;
        object->TestLimit=100;
        object->CommandList=(char*)safeMalloc(sizeof(char)*(object->TestLimit+1));
        memset(object->CommandList,'0',object->TestLimit);
        object->CommandList[object->TestLimit+1]='\0';
        return object;
    }
    if(object!=NULL&&signal!='0'){
        object->CommandList[object->counter]=signal;
        printf("(  %c  )\n", object->CommandList[object->counter]);
        object->counter++;
    }
    return object;
}    

int testIntSum(int* flag){
    int a=-20;
    int b=35;
    int c1=a+b;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(*c2!=c1){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testIntMult(int* flag){
    int a=-20;
    int b=35;
    int c1=a*b;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    if(*c2!=c1){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testIntNeutral(int* flag){
    int c1=0;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->zero((void*)c2);
    if(*c2!=c1){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}




int testDoubleSum(int* flag){
    double a=-20.2;
    double b=35.5;
    double c1=a+b;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(!CompareDouble((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testDoubleMult(int* flag){
    double a=-2.5;
    double b=50.5;
    double c1=a*b;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    if(!CompareDouble((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testDoubleNeutral(int* flag){
    double c1=0.0;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->zero((void*)c2);
    if(!CompareDouble((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}

int testFloatSum(int* flag){
    float a=-20.2f;
    float b=35.5f;
    float c1=a+b;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(!CompareFloat((void*)&c1,(void*)c2,floatEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testFloatMult(int* flag){
    float a=-2.5f;
    float b=50.5f;
    float c1=a*b;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    if(!CompareFloat((void*)&c1,(void*)c2,floatEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testFloatNeutral(int* flag){
    float c1=0.0f;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->zero((void*)c2);
    if(!CompareFloat((void*)&c1,(void*)c2,floatEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}



int testComplexSum(int* flag){
    Complex a={-20.2, 1.5};
    Complex b={35.5 , 2.5};
    Complex c1= {a.x+b.x,a.y+b.y};
    Complex* c2 =( Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(!CompareComplex((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testComplexMult(int* flag){
    Complex a={-20.2, 1.5};
    Complex b={35.5 , 2.5};
    Complex c1= {a.x*b.x - a.y*b.y,a.y*b.x +a.x*b.y};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    if(!CompareComplex((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}
int testComplexeNeutral(int* flag){
    Complex c1={0.0,0.0};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->zero((void*)c2);
    if(!CompareComplex((void*)&c1,(void*)c2,doubleEps)){
        *flag++;
        return 1;
    }else{
        return 0;
    }
}



