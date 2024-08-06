//teetat pitanupong 6630300394
#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

int display (int choose) {
	cout << "====================================" << endl;
	cout << "                MENU" << endl;
	cout << "====================================" << endl;
	cout << " 1) Insert" << endl;
	cout << " 2) Delete" << endl;
	cout << " 3) Print min to max, max to min" << endl;
	cout << " 4) Count" << endl;
	cout << " 5) Print First half and second half" << endl;
	cout << " 6) Find" << endl;
	cout << " 7) Exit" << endl;
	cout << "          Please choose > ";
	cin >> choose;	
	return choose;
}

void print (struct record *head) {
	struct record *p = head;
	
    while (p != NULL) {
        cout << p -> value << " ";
        p = p -> next;
    }
}

struct record *insert (struct record *head, int data) {
	struct record *node, *p;
	if (head == NULL) {
		head = new struct record;
		head -> value = data;
		head -> next = NULL;
	} else {
		node = new struct record;
		node -> value = data;
		if (data < head -> value) {
			node -> next = head;
			head = node;
		} else {
			p = head;
			while (p -> next != NULL) {
				if (data < p -> next -> value) {
					node -> next = p -> next;
					p -> next = node;
					break;
				} else {
					p = p -> next;
				}
			}
			if (p -> next == NULL) {
				p -> next = node;
				node -> next = NULL;
			}
		}
	}
	cout << "List : ";
	
	print (head);
	
	cout << endl << endl;
	
	return head;
}

struct record *del(struct record *head, int data) {
    struct record *node, *tmp;

    if (head == NULL) {
        cout << "List empty" << endl;
        return head;
    }

    if (data == head->value) {
        tmp = head;
        head = head -> next;
        delete (tmp);
    } else {
        node = head;
        bool found = false;
        while (node->next != NULL) {
            if (data == node -> next -> value) {
                tmp = node -> next;
                node -> next = node -> next -> next;
                delete (tmp);
                found = true;
                break;
            } else {
                node = node -> next;
            }
        }
        if (!found) {
            cout << "Can't delete number " << data << " from list!!" << endl << endl;
            return head;
        }
    }
    cout << "List : ";
    
	print (head);
	
    cout << endl << endl;

    return head;
}

void MaxtoMinRecursive(struct record *head) {
    if (head == NULL) return;

    MaxtoMinRecursive(head -> next);
    cout << head -> value << " ";
}

int count (struct record *head) {
	struct record *node;
	int count = 0;
	
	node = head;
	while (node) {
		count ++;
		node = node -> next;
	}
	
	return count;
}

void printhalf (struct record *head) {
    struct record *p = head;
    
	int mid = count(head) / 2;
    
    cout << "First half : ";
    
    for (int i = 0; i < mid; i++) {
        cout << p -> value << " ";
        p = p -> next;
    }

    cout << endl << "Second half : ";
    
    while (p != NULL) {
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << endl << endl;
}

bool find (struct record *head , int data) {
	struct record *node = head;
	
	while (node) {
		if (data == node -> value) {
			return true;
		} else {
			node = node -> next; 
		}
	}
	return false; 
}

int main () {
	struct record *head = NULL;
	int data, choose;
	
	while (1) {
		switch (display (choose)) {
			case 1:
				cout << endl << "Insert : ";
				cin >> data;
				head = insert (head, data);
				break;
			case 2:
				cout << endl << "Delete : ";
				cin >> data;
				head = del (head, data);
				break;
			case 3:
				cout << "Min to Max : ";
				print (head);
				cout << endl << "Max to Min : ";
				MaxtoMinRecursive (head);
				cout << endl << endl;
				break;
			case 4:
				cout << "Count = " << count (head) << endl << endl;
				break;
			case 5:
				printhalf (head);
				break;
			case 6:
				cout << endl << "Find : ";
				cin >> data;
				cout << (find (head, data) ? "Found" : "Not found") << endl << endl;
				break;
			case 7:
				exit(0);
				break;
			default:
				cout << "Invalid choice" << endl << endl;
		}
	}
		
	return 0;
}
