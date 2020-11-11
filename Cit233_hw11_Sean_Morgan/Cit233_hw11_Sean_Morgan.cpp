#include "LinkedList.h"
#include "Helper.h"


using namespace std;

int main() {
	Node head = Node("Sean M", 3000, NULL);
	LinkedList list = LinkedList();
	list.newNode("Sean M", 3000);
	list.newNode("Ryan M", 5000);
	list.newNode("Allen M", 5000);

	list.displayLinkedList();
	bubbleSort(list);
	cout << endl << endl;

	list.displayLinkedList();

};

