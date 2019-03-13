#include<string>
#include "Person.h"
#include<iostream>
using namespace std;
Person::Person() {}
Person::~Person() {}
void Person::setName(string s) {
	this ->name = s;
}
string Person :: getName() {
	return name;
}
void Person::setPhoneNumber(string s) {
	phoneNumber = s;
}
string Person :: getPhoneNumber() {
	return phoneNumber;
}
void Person :: print() {
	cout << "이름 : " << name << "전화번호 : " << phoneNumber << " ";
}


