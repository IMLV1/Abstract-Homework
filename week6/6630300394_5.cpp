//6630300394 teetat pitanupong
#include <iostream>
using namespace std;

struct record {
    int value;
    struct record *next;
};

struct record *front = NULL;
struct record *back = NULL;

void enqueue(int data) {
    struct record *node = new struct record;
    node -> value = data;
    node -> next = NULL;

    if (front == NULL && back == NULL) {
        front = back = node;
        back -> next = front; // make circular
    } else {
        back -> next = node;
        back = node;
        back -> next = front; // keep circular
    }
}

void josephus(int m, int n) {
    struct record *temp = front;
    struct record *prev = back;
    
    while (n > 1) {
        for (int i = 1; i < m + 1; i++) {
            prev = temp;
            temp = temp -> next;
        }
        prev -> next = temp -> next; // delete node
        delete temp;
        temp = prev -> next; // move to next node
        n--;
    }

    cout << temp -> value;
}

int main () {
    int m, n;
    
    cout << "Input N : ";
    cin >> n;
    cout << "Input M : ";
    cin >> m;
    
    for (int i = 1; i <= n; i++) {
        enqueue(i);
    }
    
    cout << "Winner = ";
	josephus(m, n);

    return 0;
}
