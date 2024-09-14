#include <iostream>
using namespace std;
 
struct record {
	int value;
	struct record *next;
};

void insertEdge(struct record *adjList[], int node, int data) {
	struct record *newNode = new struct record;
	newNode -> value = data;
	newNode -> next = NULL;
	
	if (adjList[node] == NULL) {
		adjList[node] = newNode;
	} else {
		struct record *p = adjList[node];
		while(p -> next != NULL) {
			p = p -> next;
		}
		p -> next = newNode;
	}
}

void adjacency_list(struct record *adjList[]) {
	for (int i = 0; i < 6; i++) {
		cout << "Enter #" << i << " : ";
		while(true) {
			int data;
			cin >> data;
			if (data == -1) {
				break;
			}
			insertEdge(adjList, i, data);
		}
	}
}

void display_adjacency_list(struct record *adjList[]) {
	cout << "ADJACENCY LIST\n";
	for (int i = 0; i < 6; i++) {
		struct record *p = adjList[i];
		cout << "#" << i << " : ";
		while(p != NULL) {
			cout << p -> value << " ";
			p = p -> next;
		}
		cout << "\n";
	}
}

void show_self_loops(struct record *adjList[]) {
	bool hasSelfLoop = false;
	for (int i = 0; i < 6; i++) {
		struct record *p = adjList[i];
		while(p != NULL) {
			if (p -> value == i) {
				cout << "Selfloop"<< p -> value << "\n";
				hasSelfLoop = true;
			} 
			p = p -> next;
		} 
	}
	if (!hasSelfLoop) {
        cout << "No self loops found\n";
	}
}

int main() {
	struct record *adjList[6];
	for (int i = 0; i < 6; i++) {
		adjList[i] = NULL;
	}
 	int choose;
	
	while(true) {
 		cout << "===========MENU==========\n"
 				"1) Input adjacency list\n"
 				"2) Show self loop from adjacency list\n"
 				"3) Exit\n"
 				"Please choose > ";
 		cin >> choose;
 		switch(choose) {
 			case 1:
 				adjacency_list(adjList);
 				display_adjacency_list(adjList);
 				break;
 			case 2:
 				if (adjList[0] == NULL) {
 					cout << "Empty Adjacency List\n";
				} else {
					show_self_loops(adjList);
				}
 				break;
 			case 3: 
 				cout << "Exiting...";
 				return 0;
 			default:
 				cout << "Invalid choice, please try again\n";
		}
	}
}