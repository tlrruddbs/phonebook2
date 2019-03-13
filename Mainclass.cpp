#include "Mainclass.h"
#include"Teacher.h"
#include"Student.h"
#include<string>
#include<vector>
#include<iostream>

using namespace std;

vector<Person*>personList;
Mainclass::Mainclass() {}
Mainclass::~Mainclass() {}
void Mainclass::add(Person* p) {
	personList.push_back(p);
}
void Mainclass::start() {
	int num;
	cout << "전화번호부 관리프로그램" << endl;

	do {
		cout << "=1. 추가\n=2. 삭제\n=3. 수정\n=4. 검색\n=5. 출력\n=6. 종료" << endl;
		cin >> num;
		if (num == 0) {
			cout << "잘못입력하셨습니다" << endl;
		}
		switch (num) {
		case 1:
			insert();
			break;
		case 2:
			del();
			break;
		case 3:
			adjust();
			break;
		case 4:
			search();
			break;
		case 5:
			print();
			break;
		}

	} while (num != 6);
}
void Mainclass::insert() {
	int a;
	string name;
	string phone;
	string id;
	string school;
	string type;
	Person *person = NULL;
	cout << "순서대로 입력하시오" << endl;
	cout << "학생입니까?[예=1,아니요=2]";
	cin >> a;
	if (a == 1) {
		Student* p = new Student;
		cout << "학번 : ";
		cin >> id;
		p->setId(id);
		cout << "학교 : ";
		cin >> school;
		p->setSchoolName(school);
		cout << "이름 :";
		cin >> name;
		p->setName(name);
		cout << "번호 ";
		cin >> phone;
		p->setPhoneNumber(phone);
		person = p;
		add(person);
		cout << "저장되었습니다" << endl;
	}
	else {
		cout << "선생입니까?[예=1,아니요=2]";
		cin >> a;
		if (a == 1) {
			Teacher *p = new Teacher;
			cout << "과목 : ";
			cin >> type;
			p->setClassType(type);
			person = p;
		}
		else {
			person = new Person;
		}
		cout << "이름: ";
		cin >> name;
		person->setName(name);
		cout << "번호 : ";
		cin >> phone;
		person->setPhoneNumber(phone);
		add(person);
		cout << "저장되었습니다" << endl;
	}
}
void Mainclass::del() {
	string name;
	cout << "이름을 입력하세요" << endl;
	cin >> name;
	if (eraser(name) == true) {
		cout << "삭제 되었습니다." << endl;
	}
	else {
		cout << "정보가 없습니다." << endl;
	}
}
bool Mainclass::eraser(string name) {
	for (vector<Person*>::iterator it = personList.begin(); it < personList.end(); it++) {
		Person* p = *it;
		if (p->getName() == name) {
			personList.erase(it);
			delete p;
			return true;
		}

		else {
			return false;
		}
	}
}
void Mainclass::adjust() {
	string name1, name2;
	cout << "이름을 입력하세요" << endl;
	cin >> name1;
	cout << "번호를 입력하세요" << endl;
	cin >> name2;
	if (adjustNumber(name1, name2) == true) {
		cout << "갱신되었습니다" << endl;
	}
	else {
		cout << "정보가 없습니다" << endl;
	}
}
bool Mainclass::adjustNumber(string name, string phone) {
	for (int i = 0; i < personList.size(); i++) {
		Person* p = personList.at(i);
		if (p->getName() == name) {
			p->setPhoneNumber(phone);
			return true;
		}
		else
			return false;
	}
}
void Mainclass::search() {
	string name;
	cout << "이름을 입력하세요" << endl;
	cin >> name;
	search(name);
}
void Mainclass::search(string name) {
	for (int i = 0; i < personList.size(); i++) {
		Person* p = personList.at(i);
		if (p->getName() == name) {
			p->print();
		}
	}
}
void Mainclass::print() {
	for (int i = 0; i < personList.size(); i++) {
		print(i);
	}
}
void Mainclass::print(int i) {
	personList.at(i)->print();
}