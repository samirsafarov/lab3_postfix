#pragma once
#include "stack.h"
#include <map>

typedef float RT;

class Postfix
{
protected:
	int Operator(char);
	int Line(const string&)const;
	void Bracket(const string&)const;
public:
	string Record(const string&)const;
	RT Count(const string&, map<char, RT>);
};