#include <iostream>

using namespace std;

struct node {
	int data;
	node *link;
};

class queue {
	node *front, *rear;
public:
	queue ();
	void insqueue(int);
	void delqueue ();
	void display ();
};

queue::queue () {
	front = NULL;
}

void queue::insqueue (int ele) {
	node *temp = new node;
	temp -> data = ele;
	temp -> link = NULL;
	if (front == NULL) {
		rear = front = temp;
		return;
	}
	rear -> link = temp;
	rear = rear -> link;
}

void queue::delqueue () {
	node *temp;
	if (front == NULL) {
		cout << "\nQueue is empty";
		return;
	}
	temp = front;
	front = front -> link;
	cout << "\nDeleted element is: " << temp -> data;
	delete temp;
}

void queue::display () {
	if (front == NULL) {
		cout << "\nQueue is empty";
		return;
	}
	node *c = front;
	while (c != NULL) {
		cout << "\t" << c->data;
		c = c -> link;
	}
}

int main () {
	queue q;
	int op, n;
	cout << "\nQueue Using Pointer\n1. Insert\n2. Delete\n3. Display\n4. Exit";
	do {
		cout << "\nEnter your option: ";
		cin >> op;
		switch (op) {
			case 1: cout << "\nEnter element to be inserted: ";
				cin >> n;
				q.insqueue (n);
				break;
			case 2: q.delqueue ();
				break;
			case 3: q.display ();
				break;
			case 4: break;
			default: cout << "\nInvalid Choice";
				break;
		}
	} while (op != 4);
	return 0;
}