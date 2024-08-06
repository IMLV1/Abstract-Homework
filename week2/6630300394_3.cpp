//6630300394 teetat pitanupong
#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

struct record *insert(struct record *head, int data) {
	if (head == NULL) {
		head = new struct record;
		head -> value = data;
		head -> next = NULL;
	}
	return head;
}

int main () {
	struct record *head = NULL;	
	head = insert (head,15);
	cout << head -> value;
}
