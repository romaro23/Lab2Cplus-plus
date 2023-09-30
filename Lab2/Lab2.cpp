
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
	void moveElement(int position, int steps) {
		Node* element = nullptr;;
		Node* previous = nullptr;
		Node* next = nullptr;
		for (int i = 0; i < steps; i++) {
			
			if (position == getLength(head)) {
				position = 1;
				element->next = head;
				head = element;
				next->next = nullptr;
				element = nullptr;
				previous = nullptr;
				next = nullptr;
				continue;
			}
			Node* current = head;		
			for (int i = 0; i < getLength(head); i++) {
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
				
			}
			else {
				head = next;
			}
			element->next = next->next;
			next->next = element;
			position++;
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
	void print() {
		Node* p = head;
		while (p) {
			cout << p->surname << " ";
			p = p->next;
		}
	}
};

int main()
{
	List list;
	list.pushBack("1");
	list.pushBack("2");
	list.pushBack("3");
	list.pushBack("4");
	list.pushBack("5");
	//list.pushByNumber(1, "Roman");
	//list.pushByNumber(6, "Roman");
	list.print();
	cout << endl;
	list.print();

}

