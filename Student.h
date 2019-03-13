#pragma once
#include "Person.h"
class Student : public Person
{
protected:
	string id;
	string schoolName;
public:
	Student();
	~Student();
	void setId(string s);
	string getId();
	void setSchoolName(string s);
	string getSchoolName();
	void print();
};

