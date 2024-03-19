#pragma once

typedef struct Node {
	char* symbol;
	struct Node* leftNode;
	struct Node* rightNode;
} Node;

Node* newNode();
void copyNode( const Node* from, Node* to );
Node* newNodeCopy( const Node* input );
void initNode(Node* input,char* insymbol);

void printAlgorithm( char *buff,int* offset, int *remainingSize, Node* node );

void testDotProduct();
void testVecSum();

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
int testComplexNeutral(int* flag);
