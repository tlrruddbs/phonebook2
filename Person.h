#pragma once
#include<string>
using namespace std;
class Person
{
protected:
	string name;
	string phoneNumber;
public:
	Person();
	~Person();
	void setName(string s);
	string getName();
	void setPhoneNumber(string s);
	string getPhoneNumber();
	virtual void print();
};

