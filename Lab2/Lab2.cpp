#include <string>
#include <iostream>
using namespace std;


struct Node {
	string surname;
	Node* next;
	Node(string _surname): surname(_surname), next(nullptr) {}
};
int getLength(Node* head) {
	int length = 0;
	Node* p = head;
	while (p) {
		length++;
		p = p->next;
	}
	return length;
}

struct List {
	Node* head;
	List() : head(nullptr) {}
	
	void pushBack(string surname) {
		Node* node = new Node(surname);
		if (head == nullptr) {
			head = node;
		}
		else {
			Node* current = head;
			while (current->next) {
				current = current->next;
			}
			current->next = node;
		}

	}
	void pushUp(string surname) {
		Node* node = new Node(surname);
		if (head == nullptr) {
			head = node;
		}
		else {
			node->next = head;
			head = node;
		}
	}
	void pushByNumber(int position, string surname) {
		Node* node = new Node(surname);
		if (head == nullptr) {
			head = node;
		}
		else {
			Node* current = head;
			for (int i = 0; i < position - 1; i++) {
				current = current->next;
			}
			node->next = current->next;
			current->next = node;
		}
	}
	void moveToRight(int position, int steps) {
		for (int j = 0; j < steps; j++) {
			
			Node* current = head;
			Node* element = nullptr;;
			Node* previous = nullptr;
			Node* next = nullptr;
			int length = getLength(head);
			if (position == length) {
				cout << "Can't move element" << endl;
				return;
			}
			for (int i = 0; i < length; i++) {
				if (i == position - 2) {
					previous = current;
				}
				if (i == position - 1) {
					element = current;
				}
				if (i == position) {
					next = current;
				}
				current = current->next;
			}
			if (position != 1) {
				previous->next = next;
				element->next = next->next;
				next->next = element;
			}
			else {
				element->next = next->next;
				head = next;
				next->next = element;
			}
			position++;
		}
	}
	void moveToLeft(int position, int steps) {
		for (int j = 0; j < steps; j++) {

			Node* current = head;
			Node* element = nullptr;;
			Node* previousOfNext = nullptr;
			Node* next = nullptr;
			int length = getLength(head);
			if (position == 1) {
				cout << "Can't move element" << endl;
				return;
			}
			for (int i = 0; i < length; i++) {
				if (i == position - 2) {
					next = current;
				}
				if (i == position - 1) {
					element = current;
				}
				if (i == position - 3) {
					previousOfNext = current;
				}
				current = current->next;
			}
			if (position != 2) {
				next->next = element->next;
				previousOfNext->next = element;
				element->next = next;
			}
			else {
				next->next = element->next;
				head = element;
				element->next = next;
			}
			position--;
		}
	}
	void deleteByNumber(int position) {
		Node* current = head;
		Node* previous = nullptr;
		if (position == 1) {
			head = current->next;
			delete current;
		}
		else if (position == getLength(head)) {
			for (int i = 0; i < position; i++) {
				if (i == position - 2) {
					previous = current;
				}
				current = current->next;

			}
			previous->next = nullptr;
			delete current;
		}
		else if (position > 1 && position < getLength(head)) {
			for (int i = 0; i < position - 1; i++) {
				if (i == position - 2) {
					previous = current;
				}
				current = current->next;
			}
			previous->next = current->next;
			delete current;
		}
		else {
			cout << "Wrong position" << endl;
		}
	}
	void deleteEveryNElement(int step) {
		int count = 0;
		int length = getLength(head);
		for (int i = step; i <= length; i += step) {
			deleteByNumber(i - count);
			count++;
		}
	}
	void sortByIncrease() {	
		string temp;
		for (int i = 0; i < getLength(head); i++) {
			Node* node = head;
			while (node->next) {
				if (stoi(node->surname) > stoi(node->next->surname)) {
					temp = node->surname;
					node->surname = node->next->surname;
					node->next->surname = temp;
				}
				node = node->next;
			}
		}	
	}
	void sortByDecrease() {
		string temp;
		for (int i = 0; i < getLength(head); i++) {
			Node* node = head;
			while (node->next) {
				if (stoi(node->surname) < stoi(node->next->surname)) {
					temp = node->surname;
					node->surname = node->next->surname;
					node->next->surname = temp;
				}
				node = node->next;
			}
		}
	}
	void clearList() {
		while (head) {
			Node* node = head;
			head = head->next;
			delete node;
		
		}
	}
	void print() {
		Node* node = head;
		while (node) {
			cout << node->surname << " ";
			node = node->next;
		}
		cout << endl;
	}
	List createCopy() {
		List newList;
		Node* node = head;
		while (node) {
			newList.pushBack(node->surname);
			node = node->next;
		}
		return newList;
	}
};
void combineLists(List list1, List list2) {
	Node* node = list1.head;
	Node* head = list2.head;
	while (node->next) {
		node = node->next;
	}
	node->next = head;
}
List commonElements(List list1, List list2) {
	Node* node1 = list1.head;
	List newList;
	while (node1) {
		Node* node2 = list2.head;
		while (node2) {		
			if (node1->surname == node2->surname) {
				newList.pushBack(node1->surname);
			}
			node2 = node2->next;
		}
		node1 = node1->next;
	}
	return newList;
}
int main()
{
	List list1;
	list1.pushBack("5");
	list1.pushBack("2");
	list1.pushBack("3");
	list1.pushBack("1");
	list1.pushBack("4");
	list1.print();
	//1
	cout << "Push element up" << endl;
	list1.pushUp("6");
	list1.print();
	//2
	cout << "Push element by number" << endl;
	list1.pushByNumber(6, "7");
	list1.print();
	//3
	cout << "Move element to left" << endl;
	list1.moveToLeft(2, 1);
	list1.print();

	cout << "Move element to right" << endl;
	list1.moveToRight(1, 5);
	list1.print();
	//4
	cout << "Delete element by number" << endl;
	list1.deleteByNumber(6);
	list1.print();
	//5
	cout << "Delete every n element" << endl;
	list1.deleteEveryNElement(2);
	list1.print();
	//6
	cout << "Sort by increasing" << endl;
	list1.sortByIncrease();
	list1.print();

	cout << "Sort by decreasing" << endl;
	list1.sortByDecrease();
	list1.print();
	//7
	cout << "Creating a copy" << endl;
	List list2 = list1.createCopy();
	list1.print();
	list2.print();
	//8
	cout << "Clearing the list" << endl;
	list1.clearList();
	list1.print();
	list2.print();
	List list3;
	list3.pushBack("6");
	list3.pushBack("4");
	list3.pushBack("10");
	//9
	List list4 = list2.createCopy();
	cout << "Combine two lists" << endl;
	list2.print();
	list3.print();
	combineLists(list2, list3);
	list2.print();
	//10
	cout << "List of common elements" << endl;
	List common = commonElements(list3, list4);
	common.print();
}

