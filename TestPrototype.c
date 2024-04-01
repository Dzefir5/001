#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <assert.h>
#include <float.h>
#include <malloc.h>

#include "safemalloc.h"
#include "ComplexStruct.h"
#include "TypeInfo.h"
#include "TypeFunc.h"
#include "VectorFunc.h"
#include "TestPrototype.h"


void testIntSum(){
    int a=-20;
    int b=35;
    int c1=a+b;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    assert(*c2==c1);
}
void testIntMult(){
    int a=-20;
    int b=35;
    int c1=a*b;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    assert(*c2==c1);
}
void testIntNeutral(){
    int c1=0;
    int* c2 =(int*)safeMalloc(INT_INFO()->element_size);
    INT_INFO()->zero((void*)c2);
    assert(*c2==c1);
}


void testDoubleSum(){
    double a=-20.2;
    double b=35.5;
    double c1=a+b;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    assert(compareDouble((void*)&c1,(void*)c2,DBL_EPSILON));
}
void testDoubleMult(){
    double a=-2.5;
    double b=50.5;
    double c1=a*b;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    assert(compareDouble((void*)&c1,(void*)c2,DBL_EPSILON));
}
void testDoubleNeutral(){
    double c1=0.0;
    double* c2 =(double*)safeMalloc(DOUBLE_INFO()->element_size);
    DOUBLE_INFO()->zero((void*)c2);
    assert(compareDouble((void*)&c1,(void*)c2,DBL_EPSILON));
}

void testFloatSum(){
    float a=-20.2f;
    float b=35.5f;
    float c1=a+b;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    assert(compareFloat((void*)&c1,(void*)c2,FLT_EPSILON));
}
void testFloatMult(){
    float a=-2.5f;
    float b=50.5f;
    float c1=a*b;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    assert(compareFloat((void*)&c1,(void*)c2,FLT_EPSILON));
}
void testFloatNeutral(){
    float c1=0.0f;
    float* c2 =(float*)safeMalloc(FLOAT_INFO()->element_size);
    FLOAT_INFO()->zero((void*)c2);
    assert(compareFloat((void*)&c1,(void*)c2,FLT_EPSILON));
}



void testComplexSum(){
    Complex a={-20.2, 1.5};
    Complex b={35.5 , 2.5};
    Complex c1= {a.x+b.x,a.y+b.y};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->plus((void*)&a,(void*)&b,(void*)c2);
    assert(compareComplex((void*)&c1,(void*)c2,DBL_EPSILON));
}
void testComplexMult(){
    Complex a={-20.2, 1.5};
    Complex b={35.5 , 2.5};
    Complex c1= {a.x*b.x - a.y*b.y,a.y*b.x +a.x*b.y};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->mult((void*)&a,(void*)&b,(void*)c2);
    assert(compareComplex((void*)&c1,(void*)c2,DBL_EPSILON));
}
void testComplexNeutral(){
    Complex c1={0.0,0.0};
    Complex* c2 =(Complex*)safeMalloc(COMPLEX_INFO()->element_size);
    COMPLEX_INFO()->zero((void*)c2);
    assert(compareComplex((void*)&c1,(void*)c2,DBL_EPSILON));
}


Node* newNode() {
	return (Node*)safeMalloc( TEST_INFO()->element_size );
}
void copyNode( const Node* from, Node* to ) {
    assert(from && to);
	memcpy( to, from, TEST_INFO()->element_size );
}
Node* newNodeCopy( const Node* input ) {
    Node* result = newNode();
	copyNode( input, result );
	return result;
}
void initNode(Node* input,char* insymbol){
    assert(input&&insymbol);
    input->leftNode =NULL;
    input->rightNode = NULL;
	input->symbol =strcpy((char*)safeMalloc(sizeof(char)*strlen(insymbol)) , insymbol);
}

//обратная польская нотация - изучить

void printAlgorithm(char *buff,int* offset, int *remainingSize, Node* node ) {
	assert( node ); 
	assert( node->symbol ); 
	
    if( node->leftNode ) {
		printAlgorithm(buff,offset,remainingSize, node->leftNode );
	}
    int stepLength = strlen( node->symbol ); 
	strcpy( buff+(*offset), node->symbol );
	*offset += stepLength;
	(*remainingSize) -= stepLength;
	if( node->rightNode ) {
		printAlgorithm(buff,offset,remainingSize, node->rightNode );
	}
    
}
void printNode( Node* node ) {
	assert( node ); 
	assert( node->symbol );
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

    deleteVector(&x);
    deleteVector(&y);
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
        assert( strcmp( buff, expectedResult[i] ) == 0 );
    }

    deleteVector(&x);
    deleteVector(&y);
    deleteVector(&z);
}


