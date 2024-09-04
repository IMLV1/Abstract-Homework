#include <iostream>
using namespace std;

struct record {
    char value;
    struct record *left;
    struct record *right;
};

struct Node {
    struct record *tree;
    struct Node *Next;
};

typedef struct Node *Stack;

Stack CreateStack() {
    Stack S = new struct Node;
    if (S == NULL) {
        cout << "Out of Space";
    }
    S -> Next = NULL;
    return S;
}

bool isEmpty(Stack S) {
    return S -> Next == NULL;
}

void Push(Stack S, struct record *data) {
    Stack node = new struct Node;
    if (node == NULL) {
        cout << "Out of Space";
    } else {
        node -> tree = data;
        node -> Next = S -> Next;
        S -> Next = node;
    }
}

void Pop(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack Empty";
    } else {
        Stack tmp = S -> Next;
        S -> Next = S -> Next -> Next;
        delete tmp;
    }
}

struct record *Top(Stack S) {
    if (!isEmpty(S)) {
        return S -> Next -> tree;
    } else {
    	cout << "Stack Empty";
    	return NULL;
	}
}

bool checkOperator(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/');
}

void insert(Stack S, char data) {
	struct record *tree = new struct record;
    tree -> value = data;
	if (checkOperator(data)){
	    tree -> right = Top(S);
	    Pop(S);
	    tree -> left = Top(S);
	    Pop(S);
	} else {
		tree -> left = tree -> right = NULL;
	}
	Push(S, tree);
}

void printInorder(struct record *tree) {
    if (tree == NULL) {
    	return;
	} else {
		printInorder(tree -> left);
    	cout << tree -> value << " ";
    	printInorder(tree -> right);
	}
   
   	return;
}

int main() {
    Stack S = CreateStack();
    char data;
    cout << "Input postfix : ";
    
    while (true) {
        cin >> data;

        if (data == '.') {
            break;
        } else {
            insert(S, data);
    	}
	}
    cout << "Output infix: ";
    printInorder(Top(S));

    return 0;
}
