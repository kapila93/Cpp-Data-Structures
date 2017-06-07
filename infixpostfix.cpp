#include <iostream>
#include <ctype>
const int MAX = 25;

using namespace std;

class exp {
private:
	char str[MAX];
public:
	void input();
	int instackprior(char);
	int incomprior(char);
	void convert();
};

void exp::input() {
	cout << "\nINFIX TO POSTFIX";
	cout << "\nEnter expression: ";
	gets(str);
}

int instackprior (char c) {
	switch (c) {
		case '&': return -1;
		case '+': return 1;
		case '-': return 1;
		case ')': return 0;
		case '(': return 1;
		case '^': return 3;
		case '*': return 2;
		case '/': return 2;
	}
}

int incomprior (char c) {
	switch (c) {
		case '+': return 1;
		case '-': return 1;
		case ')': return 0;
		case '(': return 4;
		case '^': return 4;
		case '*': return 2;
		case '/': return 2;	
	}
}

void convert (){
	char item, st[MAX];
	int top, i;
	st[0] = '&';
	top = i = 0;
	while (str[i]!='$') {
		item = str[i];
		if (isalpha(item)) {
			cout << item;
		}
		else if (item == ')') {
			while (st[top] != '(') {
				cout << st[top];
				top--;
			}
			top--;
		}
		else {
			while (instackprior(st[top]) >= instackprior(item)) {
				cout << st[top];
				top--;
			}
			top++;
			st[top] = item;
		}
		i++;
	}
	while (st[top] != 0) {
		cout << st[top];
		top--;
	}
}

int main () {
	exp e;
	e.input();
	e.convert();
	return 0;
}