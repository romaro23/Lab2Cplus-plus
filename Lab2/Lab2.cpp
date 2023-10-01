
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
		else if (position > 1 && position < getLength(head)){
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
	list1.pushBack("1");
	list1.pushBack("2");
	list1.pushBack("3");
	list1.pushBack("4");
	list1.pushBack("5");
	list1.print();
	List list2;
	list2.pushBack("6");
	list2.pushBack("7");
	list2.pushBack("8");
	list2.pushBack("9");
	list2.pushBack("10");
	list2.print();
	combineLists(list1, list2);
	list1.print();
	List list3 = commonElements(list1, list2);
	list3.print();
	List list4 = list3.createCopy();
	list4.print();
}

