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
	cout << "��ȭ��ȣ�� �������α׷�" << endl;

	do {
		cout << "=1. �߰�\n=2. ����\n=3. ����\n=4. �˻�\n=5. ���\n=6. ����" << endl;
		cin >> num;
		if (num == 0) {
			cout << "�߸��Է��ϼ̽��ϴ�" << endl;
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
	cout << "������� �Է��Ͻÿ�" << endl;
	cout << "�л��Դϱ�?[��=1,�ƴϿ�=2]";
	cin >> a;
	if (a == 1) {
		Student* p = new Student;
		cout << "�й� : ";
		cin >> id;
		p->setId(id);
		cout << "�б� : ";
		cin >> school;
		p->setSchoolName(school);
		cout << "�̸� :";
		cin >> name;
		p->setName(name);
		cout << "��ȣ ";
		cin >> phone;
		p->setPhoneNumber(phone);
		person = p;
		add(person);
		cout << "����Ǿ����ϴ�" << endl;
	}
	else {
		cout << "�����Դϱ�?[��=1,�ƴϿ�=2]";
		cin >> a;
		if (a == 1) {
			Teacher *p = new Teacher;
			cout << "���� : ";
			cin >> type;
			p->setClassType(type);
			person = p;
		}
		else {
			person = new Person;
		}
		cout << "�̸�: ";
		cin >> name;
		person->setName(name);
		cout << "��ȣ : ";
		cin >> phone;
		person->setPhoneNumber(phone);
		add(person);
		cout << "����Ǿ����ϴ�" << endl;
	}
}
void Mainclass::del() {
	string name;
	cout << "�̸��� �Է��ϼ���" << endl;
	cin >> name;
	if (eraser(name) == true) {
		cout << "���� �Ǿ����ϴ�." << endl;
	}
	else {
		cout << "������ �����ϴ�." << endl;
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
	cout << "�̸��� �Է��ϼ���" << endl;
	cin >> name1;
	cout << "��ȣ�� �Է��ϼ���" << endl;
	cin >> name2;
	if (adjustNumber(name1, name2) == true) {
		cout << "���ŵǾ����ϴ�" << endl;
	}
	else {
		cout << "������ �����ϴ�" << endl;
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
	cout << "�̸��� �Է��ϼ���" << endl;
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