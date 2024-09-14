#include <iostream>
using namespace std;

struct record {
	int value;
	struct record *next;
};

struct record *head = NULL;
int StartNode = 1;
int d[8], pred[8];

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
	for (int i = 0; i < 8; i++) {
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
	for (int i = 0; i < 8; i++) {
		struct record *p = adjList[i];
		cout << "#" << i << " : ";
		while(p != NULL) {
			cout << p -> value << " ";
			p = p -> next;
		}
		cout << "\n";
	}
}

int queuesize() {
	struct record *p = head;
	int size = 0;
	while(p != NULL) {
		p = p -> next;
		size++;
	}
	return size;
}

void Enqueue(int data) {
    struct record *newNode = new struct record;
    newNode -> value = data;
    newNode -> next = NULL;
    
    if (head == NULL) {
    	head = newNode;
	} else {
		struct record *p = head;
		while(p -> next != NULL) {
			p = p -> next;
		}
		p -> next = newNode;
	}
}

void dequeue() {
    if (head == NULL) {
        return;
    }
    struct record *tmp = head;
    head = head->next;
    delete tmp;
}

void breadth_frist_search(struct record *adjList[]) {
	int v, u, s = StartNode;
	int pass[8];
	for (int i = 0 ;i < 8;i++) {
		pass[i] = 0;
		d[i] = -1;
		pred[i] = -1;
	}
	pass[s] = 1;
	d[s] = 0;
	pred[s] = s;
	
	Enqueue(s);
	while (queuesize() != 0) {
		u = head -> value;
		struct record *node = adjList[u];
		while(node != NULL) {
			v = node -> value;
			if (pass[v] == 0) {
				pass[v] = 1;
				d[v] = d[u] + 1;
				pred[v] = u;
				Enqueue(v);
			}
			node = node -> next;
		}
		dequeue();
	}
	cout << "  | d | pred\n"
	        "=============\n";
	for(int i = 0;i < 8; i++){
		cout << i << " | " << d[i] << " | " << pred[i] << "\n";
	}
}

void search_path(int EndNode) {
	if (StartNode == EndNode) {
		cout << "No path found\n";
	} else {
		cout << "Path = ";
		int path[8];
		int distance = 0;
		int current = EndNode;
		while (current != StartNode) {
        	path[distance++] = current;
        	current = pred[current];
    	}
		path[distance++] = StartNode;
		for (int i = distance - 1;i > 0; i--) {
			cout << "(" << path[i] << "," << path[i - 1] << ")";
			if (i > 1) {
				cout << " , ";
			}
		} 
		cout << "\nDistance = " << d[EndNode] << "\n";
	}	
}

int main() {
	struct record *adjList[8];
	for (int i = 0; i < 8; i++) {
		adjList[i] = NULL;
	}
	int data;
	while(true) {
		cout << "===========MENU==========\n"
				"1) Input adjacency list\n"
				"2) BFS\n"
				"3) Search path\n"
				"4) Exit\n"
				"Please choose > ";
		cin >> data;
		switch(data) {
			case 1:
				adjacency_list(adjList);
				display_adjacency_list(adjList);
				break;
			case 2:
				breadth_frist_search(adjList);
				break;
			case 3:
				cout << "Enter end point : ";
				cin >> data;
				search_path(data);
				break;
			case 4:
				cout << "Exiting...";
				return 0;
			default:
 				cout << "Invalid choice, please try again\n";
		}
	}
}

/*
Start Node 1
Node 0 : 1 4 -1
Node 1 : 0 5 -1
Node 2 : 3 5 6 -1
Node 3 : 2 7 -1
Node 4 : 0 -1
Node 5 : 1 2 6 -1
Node 6 : 2 5 7 -1
Node 7 : 3 6 -1
*/
