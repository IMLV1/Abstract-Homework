#include <iostream>
using namespace std;

struct record {
    int coef;
    int pow;
    struct record *next;
};

struct record *insert(struct record *head, int c, int p) {
    struct record *node = new struct record;
    node -> coef = c;
    node -> pow = p;
    node -> next = NULL;

    if (head == NULL || head -> pow < p) {
        node -> next = head;
        head = node;
    } else {
        struct record *tmp = head;
        while (tmp -> next != NULL && tmp -> next -> pow >= p) {
            if (tmp -> next -> pow == p) {
                tmp -> next -> coef += c;
                delete (node);
                return head;
            }
            tmp = tmp -> next;
        }
        if (tmp -> pow == p) {
            tmp -> coef += c;
            delete (node);
        } else {
            node -> next = tmp -> next;
            tmp -> next = node;
        }
    }
    return head; 
}

struct record *input(struct record *head) {
    int coef, pow;
    
    while (true) {
        cin >> coef;
        if (coef == -99) break;
        cin >> pow;
        head = insert (head, coef, pow);
    }
    return head;
}

void addingPolynomials(struct record *p1, struct record *p2) {
    struct record *head = NULL;

    while (p1 != NULL || p2 != NULL) {
        int coef, pow;

        if (p1 != NULL && (p2 == NULL || p1 -> pow > p2 -> pow)) {
            coef = p1 -> coef;
            pow = p1 -> pow;
            p1 = p1 -> next;
        } else if (p2 != NULL && (p1 == NULL || p2 -> pow > p1 -> pow)) {
            coef = p2 -> coef;
            pow = p2 -> pow;
            p2 = p2 -> next;
        } else {
            coef = p1 -> coef + p2 -> coef;
            pow = p1 -> pow;
            p1 = p1 -> next;
            p2 = p2 -> next;
        }

        head = insert (head, coef, pow);
    }

    struct record *tmp = head;
    bool firstTerm = true;

    while (tmp != NULL) {
        if (tmp -> coef != 0) {
            if (firstTerm != true) {
                if (tmp -> coef > 0) {
                    cout << " + ";
                } else {
                    cout << " - ";
                    tmp -> coef = -tmp -> coef;
                }
            } 
			
            if (tmp -> pow == 0) {
                cout << tmp -> coef;
            } else if (tmp -> pow == 1) {
                cout << tmp -> coef << "x";
            } else {
                cout << tmp -> coef << "x^" << tmp -> pow;
            }
            firstTerm = false;
        }
        tmp = tmp -> next;
    }
    cout << endl;
}

int main() {
    struct record *head1 = NULL; 
    struct record *head2 = NULL; 
    
    cout << "Input P1 : ";
    head1 = input (head1);
    
    cout << "Input P2 : ";
    head2 = input (head2);
    
    cout << "Output : ";
    addingPolynomials (head1, head2);
    
    return 0;
}

