#pragma once
#include <string>
#include "Starbucks.h"
using namespace std;

class komnicjcStarbucks : public Starbucks 
{
	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);
	class Node;

};