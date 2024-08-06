//teetat pitanupong 6630300394
#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
	struct record *prev;
};

struct record *tail = NULL;

int display (int choose) {
	cout << "===================" << endl;
	cout << "        MENU" << endl;
	cout << "===================" << endl;
	cout << " 1) Insert" << endl;
	cout << " 2) Print" << endl;
	cout << " 3) Exit" << endl;
	cout << " Please choose > ";
	cin >> choose;
	return choose;
}

struct record *insert(struct record *head, int data){
	if (head == NULL && tail == NULL){
		head = new struct record;
		head -> value = data;
		head -> next = head -> prev = NULL;
		tail = head;
	} else {
		struct record *node = new struct record;
		node -> value = data;
		if (data < head->value){
			node -> next = head;
			node -> prev = NULL;
			head -> prev = node;
			head = node;
		}else{
			struct record *p = head;
			while (p -> next != NULL){
				if (data < p -> next -> value){
					node -> prev = p;
					node -> next = p -> next;
					p -> next -> prev = node;
					p -> next = node;
					break;
				} else {
					p = p -> next;	
				}
			}
			if (p -> next == NULL){
				node -> next = p -> next;
				p -> next = node;
				node -> prev = p;
				tail = node;
			}
		}
	}
	cout << "Output : ";
	
	struct record *tmp = head;
    while (tmp != NULL) {
        cout << tmp -> value << " ";
        tmp = tmp -> next;
    }
    cout << endl << endl ;
	return head;
}

void print (struct record *head) {
	cout << endl << "Print from head : ";
	
	struct record *p = head;
    while (p != NULL) {
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << endl << "Print from tail : ";
    
    struct record *tmp = tail;
    while (tmp != NULL) {
        cout << tmp -> value << " ";
        tmp = tmp -> prev;
    }
    cout << endl << endl;
}

int main () {
	struct record *head = NULL;
	int choose,data;
	while (1) {
		switch (display (choose)){
			case 1:
				cout << endl << "Enter : ";
				cin >> data;
				head = insert (head,data);
				break;
			case 2:
				print (head);
				break;
			case 3:
				exit(0);
				break;
			default:
				cout<<"Not Choice!!"<<endl<<endl;
				break;
		}
	}
	return 0;
}

