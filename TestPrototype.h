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

void testInt();
void testIntSum();
void testIntMult();
void testIntNeutral();

void testDouble();
void testDoubleSum();
void testDoubleMult();
void testDoubleNeutral();

void testFloat();
void testFloatSum();
void testFloatMult();
void testFloatNeutral();

void testComplex();
void testComplexSum();
void testComplexMult();
void testComplexNeutral();
