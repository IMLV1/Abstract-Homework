//6630300394 teetat pitanupong
#include <iostream>
using namespace std;

struct Node {
    char value;
    struct Node *next;
};
typedef struct Node *Stack;

Stack CreateStack() {
    Stack S = new struct Node;
    if (S == NULL) cout << "Out of Space";
    S -> next = NULL;
    return S;
}

bool isEmpty(Stack S) {
    return S -> next == NULL;
}

void Push(Stack S, char data) {
    Stack node = new struct Node;
    if (node == NULL) cout << "Out of Space";
    else {
    	node -> value = data;
    	node -> next = S->next;
    	S -> next = node;	
	}
}

void Pop(Stack S) {
    if (isEmpty(S)) cout << "Stack Empty";
    else {
    	Stack tmp = S -> next;
    	S -> next = S -> next -> next;
    	delete tmp;
	}
}

char Top(Stack S) {
    if (!isEmpty(S)) return S -> next -> value;
    return '\0';
}

bool isOpenBracket(char data) {
    return data == '(' || data == '{' || data == '[';
}

bool isCloseBracket(char data) {
    return data == ')' || data == '}' || data == ']';
}

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

bool match(Stack S, char data) {
    if (isEmpty(S)) return false;
    return isMatchingPair(Top(S), data);
}


int main () {
    Stack Open = CreateStack();
    Stack Close = CreateStack();
    char data;
    
	cout << "Input : ";
    while (true) {
        cin >> data;
        if (data == '.') break;
        
        if (isOpenBracket(data)) {
            Push(Open, data);
        } else if (isCloseBracket(data)) {
            if (match(Open, data)){
                Pop(Open);
            } else {
                Push(Close, data);
            }
        } 
    }

    if (!isEmpty(Open) && !isEmpty(Close)) cout << "Error! lnconsistent symbol";

    else if (!isEmpty(Open)) cout << "Error! Excess symbols";
   
    else if (!isEmpty(Close)) cout << "Error! no open symbol";
 
    else  cout << "All symbol is already balanced";

    
    return 0;
}

