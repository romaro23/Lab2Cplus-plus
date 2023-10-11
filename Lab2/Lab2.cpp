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
	
	void pushBack(string _surname) {
		Node* node = new Node(_surname);
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
	void pushUp(string _surname) {
		Node* node = new Node(_surname);
		if (head == nullptr) {
			head = node;
		}
		else {
			node->next = head;
			head = node;
		}
	}
	void pushByNumber(int position, string _surname) {
		Node* node = new Node(_surname);
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
	bool contains(string element) {
		Node* node = head;
		while (node) {
			if (node->surname == element) {
				return true;
			}
			node = node->next;
		}
		return false;
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
struct CircularList {
	Node* head;
	int size;
	CircularList() : head(nullptr), size(0) {}
	void pushBack(string _surname) {
		Node* node = new Node(_surname);
		if (head == nullptr) {
			head = node;
			size++;
		}
		else {
			Node* current = head;
			for (int i = 0; i < size - 1; i++) {
				current = current->next;
			}
			current->next = node;
			node->next = head;
			size++;
		}
	}
	void deleteNode(int position) {
		if (!head) {
			cout << "The list is empty" << endl;
			return;
		}
		Node* current = head;
		Node* previous = nullptr;
		if (position == 1) {
			if (size == 1) {
				delete head;
			}
			else {
				
				for (int i = 0; i < size - 1; i++) {
					current = current->next;
				}
				
				head = current->next->next;
				current->next = head;
				current = current->next;
			}
			
		}
		else if (position == size) {
			for (int i = 0; i < position - 1; i++) {
				if (i == position - 2) {
					previous = current;
				}
				current = current->next;
			}
			previous->next = head;
			delete current;
		}
		else {
			for (int i = 0; i < position - 1; i++) {
				if (i == position - 2) {
					previous = current;
				}
				current = current->next;
			}
			
			if (current == head) {
				head = previous;
				previous->next = current->next;
			}
			else {
				previous->next = current->next;
			}

			delete current;
		}
		size--;
	}
	void print() {
		Node* node = head;
		for (int i = 0; i < size; i++) {
			cout << node->surname << " ";
			node = node->next;
		}
		cout << endl;
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
			if (node1->surname == node2->surname && !newList.contains(node1->surname)) {
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
	List list, listCopy, listComb1, listComb2, commonList;
	list.pushBack("5");
	list.pushBack("2");
	list.pushBack("3");
	list.pushBack("1");
	list.pushBack("4");
	list.print();
	while (true) {
		cout << "1.Push back" << endl;
		cout << "2.Push up" << endl;
		cout << "3.Push by a number" << endl;
		cout << "4.Move to right" << endl;
		cout << "5.Move to left" << endl;
		cout << "6.Delete by a number" << endl;
		cout << "7.Delete every N element" << endl;
		cout << "8.Sort by the increasing" << endl;
		cout << "9.Sort by the decreasing" << endl;
		cout << "10.Clear the list" << endl;
		cout << "11.Print the list" << endl;
		cout << "12.Create a copy of the list" << endl;
		cout << "13.Combine two lists" << endl;
		cout << "14.A list of the common elements" << endl;
		cout << "15.Transer students" << endl;

		int option;
		string element;
		int position;
		int steps;
		int numberOfStudents, currentStep, count1, step, count2;
		Node* lastPosition;
		cin >> option;
		switch (option) {
		case 1:
			cout << "Enter the element" << endl;
			cin >> element;
			list.pushBack(element);
			break;
		case 2:
			cout << "Enter the element" << endl;
			cin >> element;
			list.pushUp(element);
			break;
		case 3:
			cout << "Enter the element and the position after which the element will be pushed" << endl;
			cin >> element >> position;
			list.pushByNumber(position, element);
			break;
		case 4: 
			cout << "Enter the position of the element and the number of steps" << endl;
			cin >> position >> steps;
			list.moveToRight(position, steps);
			break;
		case 5: 
			cout << "Enter the position of the element and the number of steps" << endl;
			cin >> position >> steps;
			list.moveToLeft(position, steps);
			break;
		case 6: 
			cout << "Enter the position of the element" << endl;
			cin >> position;
			list.deleteByNumber(position);
			break;
		case 7:
			cout << "Enter the step" << endl;
			cin >> steps;
			list.deleteEveryNElement(steps);
			break;
		case 8:
			list.sortByIncrease();
			break;
		case 9:
			list.sortByDecrease();
			break;
		case 10:
			list.clearList();
			break;
		case 11:
			list.print();
			break;
		case 12:
			listCopy = list.createCopy();
			listCopy.print();
			list.print();
			break;
		case 13:
			cout << "Enter the elements of the first list. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}			
				listComb1.pushBack(element);
			}
			cout << "Enter the elements of the second list. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}
				listComb2.pushBack(element);
			}
			combineLists(listComb1, listComb2);
			listComb1.print();
			break;
		case 14:
			cout << "Enter the elements of the first list. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}
				listComb1.pushBack(element);
			}
			cout << "Enter the elements of the second list. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}
				listComb2.pushBack(element);
			}
			commonList = commonElements(listComb1, listComb2);
			commonList.print();
			break;
		case 15:
			CircularList firstGroup, secondGroup;
			cout << "Enter the students of the first group. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}
				firstGroup.pushBack(element);
			}
			cout << "Enter the students of the second group. Write 'e' to stop" << endl;
			while (true) {
				cin >> element;
				if (element == "e") {
					break;
				}
				secondGroup.pushBack(element);
			}
			cout << "First group: "; firstGroup.print();
			cout << "Second group: "; secondGroup.print();
			cout << "Enter the number of students and the position of start" << endl;		
			cin >> numberOfStudents >> currentStep;
			if (numberOfStudents > firstGroup.size) {
				cout << "Not enought students in the group" << endl;
				break;
			}
			Node* current = firstGroup.head;
			count1 = 1;
			step = currentStep;
			while (count1 <= numberOfStudents) {
				if (currentStep - step * count1 == 0) {
					lastPosition = current->next;
					secondGroup.pushBack(current->surname);							
					count1++;
					current = lastPosition;
				}
				else {
					current = current->next;
				}
				currentStep++;			
			}
			for(int i = 0; i < numberOfStudents; i++) {
				if (i == 0) {
					firstGroup.deleteNode(1);
				}
				else {
					if (firstGroup.size < step) {
						step--;
					}
					firstGroup.deleteNode(step);
				}
			}
			cout << "First group: "; firstGroup.print();
			cout << "Second group: "; secondGroup.print();
			break;
		}
	}
	
}

