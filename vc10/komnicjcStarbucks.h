#pragma once
#include <string>
#include "Starbucks.h"
using namespace std;

class komnicjcStarbucks : public Starbucks 
{ 
	class Entry 
	{
		public:
		string identifier;
		double x;
		double y;
	};

	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y);

};