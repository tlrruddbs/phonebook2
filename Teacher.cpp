#include "Teacher.h"
#include<iostream>
using namespace std;
Teacher::Teacher() {}
Teacher::~Teacher() {}
void Teacher::setClassType(string s) {
	this->classType = s;
}
string Teacher :: getClassType() {
	return classType;
}
void Teacher::print() {
	Person::print();
	cout << "°ú¸ñ: " << classType << endl;
}


