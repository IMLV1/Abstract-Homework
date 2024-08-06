// 6630300394 teetat pitanupong
#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

struct record *back = NULL;

int display() {
	int select;
	cout << "===============================\n";
	cout << "            MENU\n";
	cout << "===============================\n";
	cout << "1. Enqueue\n";
	cout << "2. Dequeue\n";
	cout << "3. Exit\n";
	cout << "   Please choose > ";
	cin >> select;
	return select;
}

struct record *enqueue (struct record *front, int data) {
	struct record *node = new struct record;
	node -> value = data;
	node -> next = NULL;
	
	if (front == NULL && back == NULL) {
		front = back = node;
	} else {
		back -> next = node;
		back = node;
	}
	return front;
}

void print (struct record *front) {
	struct record *p = front;
	
	while(p != NULL) {
		cout << p -> value << " ";
		p = p -> next;
	}
	cout << endl;
}

struct record *dequeue (struct record *front) {
	struct record *tmp = front;
	
	if (front == NULL) {
		cout << "Queue Empty Can't Dequeue!!!\n";
		return front;
	}

	if (front -> next == NULL) {
		front = back = NULL;
	} else {
		front = front -> next;
	}
	cout << "Dequeue " << tmp -> value << " Success!\n";
	delete tmp;
	
	return front;
}

int main () {
	struct record *front = NULL;
	int data;
	
	while (true) {
		switch (display ()) {
			case 1:
				cout << "Enqueue : ";
				cin >> data;
				front = enqueue(front, data);
				cout << "Q = ";
				print(front);
				break;
			case 2:
				front = dequeue(front);
				break;
			case 3:
				cout << "Exiting...";
				return 0;
				break;
			default:
				cout << "Plaese Select 1-3\n";
				break;
		}
	}
}