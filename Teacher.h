#pragma once
#include "Person.h"
class Teacher :public Person
{
protected:
	string classType;
public:
	Teacher();
	~Teacher();
	void setClassType(string s);
	string getClassType();
	void print();
};

