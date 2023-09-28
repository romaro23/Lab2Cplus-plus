
#include <iostream>
using namespace std;

struct Node {
	string surname;
	Node* next;
	Node(string _surname): surname(_surname), next(nullptr) {}
};
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
	/*void deleteByNumber(int position) {
		Node* current = head;
		for (int i = 0; i < position; i++) {
			current = current->next;
		}
		
	}*/
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
	list.pushByNumber(1, "Roman");
	list.pushByNumber(6, "Roman");
	list.print();

}

