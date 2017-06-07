#include <iostream>

const int MAX = 10;

using namespace std;

class queue {
private:
	int rear, front, a[MAX];
public:
	void init ();
	void insert (int);
	void del ();
	void display ();
	void count ();
};

void queue::init () {
	rear = front = -1;
}

void queue::insert (int d) {
	if (rear >= MAX) {
		cout << "\nQueue Overflow";
		return;
	}
	a[++rear] = d;
}

void queue::del () {
	if (front == rear) {
		cout << "\nQueue Underflow";
		return;
	}
	cout << "\nDeleted element is: " << a[++front];
}

void queue::display () {
	if (front == rear) {
		cout << "\nQueue Underflow";
		return;
	}
	cout << "\nElements in the queue are: " << endl;
	for (int i = front + 1; i < rear +1; i++) {
		cout << a[i] << "\t";
	}
}

void queue::count () {
	cout << "\nNumber of elements in the queue are: " << rear - front;
}

int main () {
	queue q;
	int data, ch;
	q.init ();
	cout << "\nQUEUE USING ARRAY\n1. Insert\n2. Delete\n3. Display\n4. Count\n5. Exit";
	do {
		cout << "\nEnter choice: ";
		cin >> ch;
		switch (ch) {
			case 1: {
				cout << "\nEnter data to be inserted: ";
				cin >> data;
				q.insert (data);
				break;
			}
			case 2: {
				q.del ();
				break;
			}
			case 3: {
				q.display();
				break;
			}
			case 4: {
				q.count ();
				break;
			}
			case 5: break;
			default: cout << "\nInvalid Choice!";
		}
	} while (ch != 5);
	return 0;
}