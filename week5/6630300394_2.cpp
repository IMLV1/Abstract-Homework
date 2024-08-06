//teetat pitanupong 6630300394
#include <iostream>
using namespace std;

struct Node {
	int value;
	struct Node *next;
};

typedef struct Node *Stack;

Stack CreateStack() {
	Stack S = new struct Node;
	if (S == NULL) cout << "Out Of Space" << endl;
	S -> next = NULL;
	return S;
}

int Display () {
	int select;
	cout << "========================" << endl;
 	cout << "          MENU" << endl;
	cout << "========================" << endl;
	cout << " 1) Push" << endl;
	cout << " 2) Top" << endl;
	cout << " 3) Pop" << endl;
	cout << " 4) Pop All" << endl;
	cout << " 5) Exit" << endl;
	cout << "    Please choose > ";
	cin >> select;
	return select;
}

void Push (Stack S, int data) {
	Stack tmp = new struct Node;
	if (tmp == NULL) cout << "Out Of Space" << endl;
	else {
		tmp -> value = data;
		tmp -> next = S -> next;
		S -> next = tmp;
	}
}

bool isEmpty (Stack S) {
	return S -> next == NULL;
}

int Top (Stack S) {
	if (!isEmpty (S)) return S -> next -> value;
	cout << "Stack Empty" << endl;
	return 0;
}

void Pop(Stack S) {
	if (isEmpty(S)) cout << "Stack Empty" << endl;
	else {
		Stack tmp = S -> next;
		S -> next = S -> next -> next;
		delete tmp;
		cout << "Delete" << endl;
	}
}

void PopALL (Stack S){
	while (S -> next != NULL) {
		cout << "Top : " << Top(S) << endl;
		Pop(S);
	}
}

int main () {
	Stack S = CreateStack();
	int data;
	while (true) {
		switch (Display ()) {
			case 1:
				cout << "Push : ";
				cin >> data;
				Push(S, data);
				break;
			case 2:
				if (isEmpty(S)) Top(S);
				else cout << "Top : " << Top(S) << endl;
				break;
			case 3:
				if (isEmpty (S)) Pop (S);
				else {
					cout << "Top : " << Top(S) << endl;
					Pop(S);
				}
				break;
			case 4:
				if (isEmpty (S)) Pop(S);
				else {
					PopALL(S);
					Pop(S);
				}
				break;
			case 5:
				cout << "Exiting...";
				exit(0);
				break;
			default:
				cout << "Please Select 1-5" << endl;
				break;
		}
	}
}
