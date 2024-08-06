//6630300394 teetat pitanupong
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int value;
    struct Node *next;
};

typedef struct Node *Stack;

Stack CreateStack() {
    Stack S = new struct Node;
    if (S == NULL) cout << "Out of space\n";
    S -> next = NULL;
    return S;
}

void Push(Stack S, int data) {
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

void Pop(Stack S) {
    if (isEmpty(S)) cout << "Empty Stack\n";
    else {
        Stack tmp = S -> next;
        S -> next = S -> next -> next;
        delete tmp;
    }
}

int Top(Stack S) {
    if (!isEmpty(S)) return S->next->value;
    cout << "Empty Stack\n";
    return 0;
}

bool isOperator(char data) {
    return (data == '+' || data == '-' || data == '*' || data == '/');
}

int PostfixExpression(string postfix) {
    Stack S = CreateStack();
    stringstream ss(postfix);
    string tmp;

    while (ss >> tmp) {
        if (isdigit(tmp[0]) || (tmp[0] == '-' && tmp.length() > 1)) {
            Push(S, stoi(tmp));
        } else if (isOperator(tmp[0])) {
            int operand2 = Top(S); Pop(S);
            int operand1 = Top(S); Pop(S);
            
            switch (tmp[0]) {
                case '+':
                    Push(S, operand1 + operand2);
                    break;
                case '-':
                    Push(S, operand1 - operand2);
                    break;
                case '*':
                    Push(S, operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) exit(1);
                    Push(S, operand1 / operand2);
                    break;
            }
        }
    }
    
    int result = Top(S);
    Pop(S);
    return result;
}

int main() {
    string postfix;
    char data;
    
    cout << "Input : ";
    while (data != '.') {
    	data = getchar();
        postfix += data;
    }
    
    int result = PostfixExpression(postfix);
    cout << "Output : " << result;

    return 0;
}

