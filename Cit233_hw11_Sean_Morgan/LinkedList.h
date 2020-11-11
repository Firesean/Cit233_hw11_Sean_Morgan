#pragma once
#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

class LinkedList {
private:
	int length = 0;
	Node* head, * tail;
public:

	LinkedList() {
		int length = 0;
		Node* head, * tail;
	}

	Node* getHead() {
		return this->head;
	}

	Node* operator[](int index){
		Node* result = this->getHead();
		if (index >= this->getLength()) {
			return NULL;
		}
		for (int i = 0; i < index; i++) {
			result = result->getNext();
		}
		return result;
	}

	void newNode(string name, float sal) {
		Node* node = new Node();
		node->setName(name);
		node->setNext(this->head);
		node->setSalary(sal);
		this->head = node;
		this->length++;
	}

	int getLength() {
		return this->length;
	}

	void displayLinkedList() {
		int i = 1;
		Node* curNode = this->head;
		for (int i = 0; i < this->getLength(); i++) {
			cout << i << ": " << curNode->getName() << endl;
			if (curNode == NULL) { break; }
			curNode = curNode->getNext();
		}
	}

	void swapNodes(Node& n1, Node& n2) {
		Node& tmp = n1;
		n1 = n2;
		n2 = tmp;
	}

	void findNode() {
		
	}
};

void bubbleSort(LinkedList &list) { // Bubble sort compares by pairs and switches values whether they are bigger or not
	for (int i = 0; i < list.getLength() - 1; i++) { // Goes through each integer
		for (int j = 0; j < list.getLength() - i - 1; j++) { // Goes through each integer from the remaining numbers based on i
			if (list[j]->getName() > list[j + 1]->getName()) { // Looks at the position infront of j and sees if it is bigger or not
				// Swap has 3 assignments :D <---- Count the number of assignments
				list.swapNodes(*list[j], *list[j + 1]); // Swaps values if j is bigger
			}
		}
	}
}