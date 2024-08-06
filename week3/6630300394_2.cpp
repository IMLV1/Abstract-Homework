//teetat Pitanupong 6630300394
#include <iostream>
#include <string>
using namespace std;

struct record {
    char c;               
    struct record* next;  
};

int Menu(int choose) {
    cout << "====================" << endl;
    cout << "        MENU" << endl;
    cout << "====================" << endl;
    cout << " 1) Input secret code" << endl;
    cout << " 2) Decode" << endl;
    cout << " 3) Exit" << endl;
    cout << "Please choose > ";
    cin >> choose;
    return choose;
}

struct record *insert(struct record *head) { 
    string data;
    cout << "Code : ";
    cin >> data; 

    for (int i = 0; i < data.length(); i++) { 
        if (data[i] == '.') { 
            break;
        }
        struct record *node = new record; 
        node -> c = data[i];    
        node -> next = head; 
        head = node;       
    }
    cout << endl;
    return head;
}

void decode(struct record *head) {
    struct record* p = head;

    while (p != NULL) {
        cout << p -> c;
        p = p -> next;
    }
    cout << endl << endl;
}

int main() {
    struct record *head = NULL; 
    int choose;

    while (1) {
        switch (Menu(choose)) {
            case 1:
                head = insert(head);  
                break;
            case 2:
            	cout << "Answer : ";
                decode(head);  
                break;
            case 3:
                exit(0);
            default:
                cout << "No choice" << endl;       
        }
    }
}

