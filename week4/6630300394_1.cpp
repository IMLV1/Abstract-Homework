//teetat pitanupong 6630300394
#include <iostream>
using namespace std;

struct record *tail = NULL;

struct record {
	int value;
	struct record *next;
	struct record *prev;
};

int display (int choose) {
	cout << "===============MENU===============";
	cout << endl << " 1) Insert";
	cout << endl << " 1) Print min to max & max to min";
	cout << endl << " 3) Exit";
	cout << endl << "==================================";
	cout << endl << "       Please choose > ";
	cin >> choose;
	return choose;
}

void print (struct record *head) {
	struct record *p = head;
	
	while (p) {
		cout << p -> value << " ";
		p = p -> next;
	}
}

void Maxtomin (struct record *head) {
	struct record *p = tail;
	
	while (p) {
		cout << p -> value << " ";
		p = p -> prev;
	}
}

struct record *insert (struct record *head, int data) {
	if (head == NULL && tail == NULL) {
		head = new struct record;
		head -> value = data;
		head -> next = head -> prev = NULL;
		tail = head;
	} else {
		struct record *node = new struct record;
		node -> value = data;
		if (data < head -> value) {
			node -> next = head;
			node -> prev = NULL;
			head -> prev = node;
			head = node;
		} else {
			struct record *p = head;
			while (p -> next != NULL) {
				if (data < p -> next -> value) {
					node -> next = p -> next;
					node -> prev = p;
					p -> next -> prev = node;
					p -> next = node;
					break;
				} else {
					p = p -> next;
				}
			}
			if (p -> next == NULL) {
				p -> next = node;
				node -> prev = p;
				node -> next = NULL;
				tail = node;			
			}
		}
	}
	cout << endl;
	
	return head;
}

int main () {
	struct record *head = NULL;
	int choose, data;
	while (1) {
		switch (display (choose)) {
			case 1:
				cout << endl << "Insert : ";
				cin >> data;
				head = insert (head, data);
				break;
			case 2:
				cout << endl <<"Min to max : ";
				print (head);
				cout << endl << "Max to min : ";
				Maxtomin (head);
				cout << endl << endl;
				break;
			case 3:
				cout << endl << "Exiting...";
				exit(0);
			default:
				cout << endl << "Invalid choice" << endl << endl;
		}
	}
}
