
#include "Student.h"
#include<iostream>
using namespace std;
Student::Student() {}
Student::~Student() {}
void Student::setId(string s) {
	this->id = s;
}
string Student :: getId() {
	return id;
}
void Student::setSchoolName(string s) {
	schoolName = s;
}
string Student::getSchoolName() {
	return schoolName;
}
void Student::print() {
	Person::print();
	cout << "학번: " << id << "학교: " << schoolName << endl;
}

