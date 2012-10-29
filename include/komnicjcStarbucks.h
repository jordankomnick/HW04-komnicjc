#ifndef STARBUCKS_GUARD
#define STARBUCKS_GUARD
#pragma once
#include "Tree.h"
using namespace std;

class komnicjcStarbucks : public Starbucks 
{
public:
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
private:
	Node* insert(Entry* e, Node* root);
	Tree* locations;
};
#endif