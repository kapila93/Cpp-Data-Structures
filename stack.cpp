#include <iostream>
const int MAX = 10;
using namespace std;



class stack {
private:
	int a[MAX], sp;
public:
	void init ();
	void push (int);
	void pop ();
	void display ();
	void count ();
};

void stack::init () {
	sp = -1;
}

void stack::push(int d) {
	if (sp > MAX - 1) {
		cout << "\nStack Overflow";
		return;
	}
	a[++sp] = d;
}

void stack::pop () {
	if (sp < 0) {
		cout << "\nStack Underflow";
		return;
	}
	cout << "\nPopped element is: " << a[sp];
	sp--;
}

void stack::display () {
	if (sp < 0) {
		cout << "\nStack Underflow";
		return;
	}
	cout << "\nElements in the stack are: " << endl;
	for (int i = sp; i > -1; i--) {
		cout << a[i] << "\t";
	}
}

void stack::count () {
	cout << "\nThe number of elements in the stack are: " << sp + 1;
}

int main () {
	stack s;
	int data, ch;
	s.init();
	cout << "\nSTACK USING ARRAY\n1. PUSH\n2. POP\n3. Display\n4. Count\n5. Exit";
	do {
		cout << "\nEnter choice: ";
		cin >> ch;
		switch (ch) {
			case 1: { 
				cout << "\nEnter the element to be inserted: ";
				cin >> data;
				s.push(data);
				break;
			}
			case 2: {
				s.pop();
				break;
			}
			case 3: {
				s.display ();
				break;
			}
			case 4: {
				s.count ();
				break;
			}
			case 5: break;
			default: cout << "\nInvalid choice!";
		}
	} while (ch != 5);
	return 0;
}