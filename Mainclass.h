#pragma once
#include "Person.h"
class Mainclass
{
protected:
	string name;
public:
	Mainclass();
	~Mainclass();
	void add(Person* p);
	void start();
	void insert();
	void del();
	bool eraser(string name);
	void adjust();
	bool adjustNumber(string name, string phone);
	void search();
	void search(string name);
	void print();
	void print(int i);
};

