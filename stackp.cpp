#include <iostream>

using namespace std;

struct link {
	int data;
	link *next;
};

class linklist {
private:
	link *first;
public:
	linklist () {
		first = NULL;
	}
	void push (int);
	void pop();
	void display();
};

void linklist::push (int d) {
	link *l1 = new link;
	l1 -> data = d;
	l1 -> next = first;
	first = l1;
}

void linklist::pop () {
	if (first == NULL) {
		cout << "\nStack Underflow";
		return;
	}
	link *l2 = new link;
	l2 = first;
	first = first -> next;
	cout << "\nPopped element is: " << l2 -> data;
}

void linklist::display () {
	if (first == NULL) {
		cout << "\nStack Underflow";
		return;
	}
	cout << "\nElements in the stack are: " << endl;
	link *c = first;
	while (c != NULL) {
		cout << c -> data << "\t";
		c = c -> next;
	}
}

int main () {
	linklist s;
	int data, ch;
	cout << "\nSTACK USING POINTER\n1. PUSH\n2. POP\n3. Display\n4. Exit";
	do {
		cout << "\nEnter choice: ";
		cin >> ch;
		switch (ch) {
			case 1: {
				cout << "\nEnter the element to be inserted: ";
				cin >> data;
				s.push (data);
				break;
			}
			case 2: {
				s.pop ();
				break;
			}
			case 3: {
				s.display();
				break;
			}
			case 4: break;
		}
	} while (ch != 4);
	return 0;
}