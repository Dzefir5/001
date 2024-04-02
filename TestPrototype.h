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
void testDouble();
void testFloat();
void testComplex();
