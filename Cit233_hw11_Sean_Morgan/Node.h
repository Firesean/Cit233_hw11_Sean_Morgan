#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node {
private:
	double salary;
	string name;
	Node* next;

public:
	Node() {
		this->salary = 0;
		this->name = " ";
		this->next = NULL;
	}

	Node(string name, double salary, Node* next) {
		this->salary = salary;
		this->name = name;
		this->next = next;
	}

	double getSalary() {
		return this->salary;
	}

	string getName() {
		return this->name;
	}

	Node* getNext() {
		return this->next;
	}

	void setSalary(double sal) {
		this->salary = sal;
	}

	void setName(string name) {
		this->name = name;
	}

	void setNext(Node* next) {
		this->next = next;
	}

	void displaySelf() {
		cout << "Name : " << this->getName() << " Salary : " << this->getSalary() << " ";
		this->getNext()->displaySelf();
	}
};