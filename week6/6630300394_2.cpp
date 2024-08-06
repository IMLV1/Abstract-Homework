//6630300394 teetat pitanupong
#include <iostream>
#include <string>

using namespace std;

struct Node {
	char value;
	struct Node *next;
};

typedef struct Node *Stack;

Stack CreateStack() {
	Stack S = new struct Node;
	if (S == NULL) cout << "Out of space\n";
	S -> next = NULL;
	return S;
}

void Push(Stack S, char data) {
	Stack node = new struct Node;
	if (node == NULL) cout << "Out of space\n";
	else {
		node -> value = data;
		node -> next = S -> next;
		S -> next = node;	 
	}
}

bool isEmpty(Stack S) {
	return S -> next == NULL;
}

void Pop (Stack S) {
	if(isEmpty(S)) cout << "Empty Stack\n";
	else {
		Stack tmp = S -> next;
		S -> next = S -> next -> next;
		delete tmp;
	}
}

char Top(Stack S) {
	if (!isEmpty(S)) return S -> next -> value;
	cout << "Empty Stack\n";
	return '\0';
}

bool checkOperator(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/');
}

int peiorityOperator(char data) {
    if (data == '+' || data == '-') return 1;
    if (data == '*' || data == '/') return 2;
    return 0;
}

string infixToPostfix(string infix) {
    Stack S = CreateStack();
    string postfix = "";
    string number;

    for (int i = 0; i < infix.length(); i++) {
        char data = infix[i];

        if (data == ' ') continue; // Skip spaces
			
        if (isdigit(data)) {
        	number += data;
             // Append digit to stringstream
        } else {
            if (number.length() > 0) {
                postfix += number;
                postfix += ' ';
                number.clear(); // Clear any error flags
            }
        if (checkOperator(data)) {
                while (!isEmpty(S) && Top(S) != '(' && peiorityOperator(Top(S)) >= peiorityOperator(data)) {
                    postfix += Top(S);
                    postfix += ' ';
                    Pop(S);
                }
                Push(S, data);
            } else if (data == '(') {
                Push(S, data);
            } else if (data == ')') {
                while (!isEmpty(S) && Top(S) != '(') {
                    postfix += Top(S);
                    postfix += ' ';
                    Pop(S);
                }
                if (!isEmpty(S) && Top(S) == '(') {
                    Pop(S); // Pop '('
                }
            }
        }
    }
    
    // Append any remaining number
    if (number.length() > 0) {
        postfix += number;
        postfix += ' ';
    }

    // Pop all operators
    while (!isEmpty(S)) {
        postfix += Top(S);
        postfix += ' ';
        Pop(S);
    }
    
    return postfix;
}

int main () {
	string infix = "";
	char data;
	
	cout << "Input : ";
	while (true) {
        data = getchar();
        if (data == '.') break; 
        infix += data;
    }
	
	string postfix = infixToPostfix(infix);
	cout << "Output : " << postfix;
	
	return 0;
}
