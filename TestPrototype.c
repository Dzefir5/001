#include <stdio.h>
#include <string.h>
#include <limits.h>
#include "CustomHeader.h"
#include <assert.h>
#include <float.h>
#include <malloc.h>

int testIntSum(int* flag){
    int a=-20;
    int b=35;
    int c1=a+b;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(*c2!=c1){
        (*flag)++;
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
        (*flag)++;
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
        (*flag)++;
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
    if(!CompareDouble((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
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
    if(!CompareDouble((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
        return 1;
    }else{
        return 0;
    }
}
int testDoubleNeutral(int* flag){
    double c1=0.0;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->zero((void*)c2);
    if(!CompareDouble((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
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
    if(!CompareFloat((void*)&c1,(void*)c2,FLT_EPSILON)){
        (*flag)++;
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
    if(!CompareFloat((void*)&c1,(void*)c2,FLT_EPSILON)){
        (*flag)++;
        return 1;
    }else{
        return 0;
    }
}
int testFloatNeutral(int* flag){
    float c1=0.0f;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->zero((void*)c2);
    if(!CompareFloat((void*)&c1,(void*)c2,FLT_EPSILON)){
        (*flag)++;
        return 1;
    }else{
        return 0;
    }
}



int testComplexSum(int* flag){
    Complex a={-20.2, 1.5};
    Complex b={35.5 , 2.5};
    Complex c1= {a.x+b.x,a.y+b.y};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    if(!CompareComplex((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
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
    if(!CompareComplex((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
        return 1;
    }else{
        return 0;
    }
}
int testComplexNeutral(int* flag){
    Complex c1={0.0,0.0};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->zero((void*)c2);
    if(!CompareComplex((void*)&c1,(void*)c2,DBL_EPSILON)){
        (*flag)++;
        return 1;
    }else{
        return 0;
    }
}


Node* newNode() {
	return (Node*)malloc( TEST_INFO()->element_size );
}
void copyNode( const Node* from, Node* to ) {
	memcpy( to, from, TEST_INFO()->element_size );
}
Node* newNodeCopy( const Node* input ) {
    Node* result = newNode();
	copyNode( input, result );
	return result;
}
void initNode(Node* input,char* insymbol){
    input->leftNode =NULL;
    input->rightNode = NULL;
	input->symbol =insymbol; // demo only, use malloc()+strcpy() in real life! 
}


void printAlgorithm(char *buff,int* offset, int *remainingSize, Node* node ) {
	assert( node ); // not null
	assert( node->symbol ); // not null
	
    if( node->leftNode ) {
		printAlgorithm(buff,offset,remainingSize, node->leftNode );
	}
    int stepLength = strlen( node->symbol ); // separator + lexem
	strcpy( buff+(*offset), node->symbol );
	*offset += stepLength;
	(*remainingSize) -= stepLength;
	if( node->rightNode ) {
		printAlgorithm(buff,offset,remainingSize, node->rightNode );
	}
    
}
void printNode( Node* node ) {
	assert( node ); // not null
	assert( node->symbol ); // not null
    printf("%s\n",node->symbol);
    if(node->leftNode){
        printf(" left : %s\n",node->leftNode->symbol);
    }else{
        printf(" left : Null\n");
    }
    if(node->rightNode){
        printf(" right : %s\n",node->rightNode->symbol);
    }else{
        printf(" right : Null\n");
    }
}
static const char *X1 = "x1";
static const char *Y1 = "y1";
static const char *X2 = "x2";
static const char *Y2 = "y2";
static const char *X3 = "x3";
static const char *Y3 = "y3";
static const char *CROSS = "*";
static const char *PLUS = "+";
static const char *ZERO = "0";

static const char *expectedResult = "x1*y1+x2*y2+x3*y3";

void testDotProduct() {
	Node* fill = newNode();
	Vector* x =createVector(TEST_INFO(),3,fill);
	initNode( (Node*)getFromVector(x,0), X1 );
	initNode( (Node*)getFromVector(x,1), X2 );
	initNode( (Node*)getFromVector(x,2), X3 );
	Vector* y =createVector(TEST_INFO(),3,fill);
	initNode( (Node*)getFromVector(y,0), Y1 );
	initNode( (Node*)getFromVector(y,1), Y2 );
	initNode( (Node*)getFromVector(y,2), Y3 );
	Node dotProduct ;
    TEST_INFO()->zero(&dotProduct);
	scalarProduct( x, y, (void*)&dotProduct );
	
    
	char buff[100];
	int remainingSize = sizeof(buff);
    int offset = 0;

    printAlgorithm(buff,&offset,&remainingSize, &dotProduct );
    assert( strcmp( buff, expectedResult ) == 0 );

    //printf("\n%s\n",buff);
    //printAlgorithm(bufferStart,':',&remainingSize, &dotProduct );
}
void testVecSum() {
	Node* fill = newNode();
	Vector* x =createVector(TEST_INFO(),3,fill);
	initNode( (Node*)getFromVector(x,0), X1 );
	initNode( (Node*)getFromVector(x,1), X2 );
	initNode( (Node*)getFromVector(x,2), X3 );
	Vector* y =createVector(TEST_INFO(),3,fill);
	initNode( (Node*)getFromVector(y,0), Y1 );
	initNode( (Node*)getFromVector(y,1), Y2 );
	initNode( (Node*)getFromVector(y,2), Y3 );
	Vector* z =plusVector(x,y);

    char expectedResult[3][6]={"x1+y1","x2+y2","x3+y3"};
    for(int i = 0;i<getVectorSize(z);i++){
        char buff[10];
	    int remainingSize = sizeof(buff);
        int offset = 0;
        printAlgorithm(buff,&offset,&remainingSize, (Node*)getFromVector(z,i));
        //printf("_%s_\n",buff);
        assert( strcmp( buff, expectedResult[i] ) == 0 );
    }
    
    //assert( strcmp( buff, expectedResult ) == 0 );

    //printf("\n%s\n",buff);
    //printAlgorithm(bufferStart,':',&remainingSize, &dotProduct );
}


