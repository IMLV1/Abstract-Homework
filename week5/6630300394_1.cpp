//teetat Pintanupong 6630300394
#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
    struct record *prev;
};

struct doublylinklist {
    struct record *head;
    struct record *tail;
};

int count = 0;

int Display() {
    int select;
    cout << "========================" << endl;
    cout << "          MENU" << endl;
    cout << "========================" << endl;
    cout << " 1) Insert" << endl;
    cout << " 2) Delete" << endl;
    cout << " 3) Print min to max, max to min" << endl;
    cout << " 4) Count" << endl;
    cout << " 5) Exit" << endl;
    cout << "    Please choose > ";
    cin >> select;
    return select;
}

struct doublylinklist insert(struct doublylinklist box, int data) {
    struct record *head = box.head;
    struct record *tail = box.tail;

    struct record *node = new record;
    node -> value = data;
    node -> next = NULL;
    node -> prev = NULL;

    if (head == NULL) {
        head = tail = node;
    } else {
        if (data < head->value) {
            node -> next = head;
            head -> prev = node;
            head = node;
        } else {
            struct record *p = head;
            while (p -> next != NULL) {
                if (data < p -> next -> value) {
                    node -> next = p -> next;
                    p -> next -> prev = node;
                    node -> prev = p;
                    p -> next = node;
                    break;
                } else {
                    p = p -> next;
                }
            }
            if (p->next == NULL) {
                node -> next = p -> next;
                node -> prev = p;
                p -> next = node;
                tail = node;
            }
        }
    }
	count++;
	
    box.head = head;
    box.tail = tail;
    return box;
}

struct doublylinklist del(struct doublylinklist box, int data) {
	struct record *head = box.head;
    struct record *tail = box.tail;
    struct record *tmp;
    bool isfound = false;
    
    if (data == head -> value) {
    	tmp = head;
    	if (head -> next == NULL) head = tail = NULL; 		
    	else {
    		head = head -> next;
    		head -> prev = NULL;
		}
		isfound = true;
		delete tmp;
	} else if (data == tail -> value) {
		tmp = tail;
		tail = tail -> prev;
		tail -> next = NULL;
		isfound = true;
		delete tmp;
	} else {
		struct record *p = head;
		while (p -> next != NULL) {
			if (data == p -> next -> value) {
				tmp = p -> next;
				p -> next = p -> next -> next;
				p -> next -> prev = p;
				isfound = true;
				delete tmp;
				break;
			} else {
				p = p -> next;
			}
		}
	}
	if (!isfound) cout << "Can't Delete Number " << data << " From List" << endl; 
	else {
		count--;
		cout << "Success" << endl;
	}
	
	box.head = head;
    box.tail = tail;
    return box;
}

void print(struct record *head) {
    struct record *p = head;
    while (p != NULL) {
        cout << p -> value << " ";
        p = p -> next;
    }
    cout << endl;
}

void printMaxtomin(struct record *tail) {
    struct record *p = tail;
    while (p != NULL) {
        cout << p -> value << " ";
        p = p -> prev;
    }
    cout << endl;
}

int main() {
    struct doublylinklist box;
    box.head = NULL;
    box.tail = NULL;

    int data;

    while (true) {
        switch (Display()) {
            case 1:
                cout << "Insert: ";
                cin >> data;
                box = insert(box, data);
                cout << "List = ";
                print(box.head);
                break;
            case 2:
               	cout << "Delete : ";
               	cin >> data;
               	if (box.head == NULL) cout << "List Empty" << endl;
            	else box = del (box, data);
                break;
            case 3:
            	if (box.head == NULL) cout << "List Empty" << endl;
               	else {
               		cout << "Min to max : ";
               		print(box.head);
               		cout << "Max to min : ";
               		printMaxtomin(box.tail);
				   }
                break;
            case 4:
    			cout << "Size = " << count << endl;
                break;
            case 5:
                cout << "Exiting...";
                exit(0);
                break;
            default:
                cout << "Please select 1-5" << endl;
                break;
        }
    }
}

