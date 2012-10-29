#ifndef NODE_GUARD
#define NODE_GUARD
#include "Starbucks.h"

class Node
{
public:
	Node();
	Entry* data;
	Node* left;
	Node* right;
	Node* parent;
};
#endif