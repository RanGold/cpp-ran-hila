#ifndef ANALYZER_H
#define ANALYZER_H

#include <list>
#include "Token.h"
using namespace std;

class Analyzer{
	
public:
	virtual void analyze(const list<Token*>& tokens) = 0;
};

#endif