#include <iostream>
#include <vector>
#define MAX 6
using namespace std;

vector<int> adjList[MAX];

int pass[MAX];
int pred[MAX];
int d[MAX];
int f[MAX];
int degree[MAX];
int time = 0;
int V, E;
int u, v;

void print_adjacency_list() {
	cout << "ADJACENCY LIST\n";
	for (int i = 0; i < V; i++) {
		cout << "#" << i << " : ";
		for (int j = 0;j < degree[i]; j++) {
			cout << adjList[i][j] << " ";
		}
		cout << "\n";
	}
}

void adjacency_list() {
	cout << "Enter vertex and Edge : ";
	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		cout << "Enter : ";
		cin >> u >> v;
		adjList[u].push_back(v); 
		degree[u]++;
	}
	print_adjacency_list();
}

void DFS_visit(int u) {
	pass[u] = 1;
	d[u] = ++time;
	for (int i = 0; i < degree[u]; i++) {
		v = adjList[u][i];
		if (pass[v] == 0) {
			pred[v] = u;
			DFS_visit(v);
		}
	}
	pass[u] = 1;
	f[u] = ++time;
}

void depth_first_search(int S) {
	time = 0;
	for (int i = 0; i < V; i++) {
		pass[i] = 0;
		pred[i] = -1;
		d[i] = -1;
		f[i] = -1;
	}
	u = S;
	DFS_visit(u);
	for (int i = 0 ; i < V ; i++) {
		if (pass[i] == 0) {
			DFS_visit(i);
		}
	}
	cout << "   l  d   f   pred\n"
			"---|-----------------\n";
	for (int i = 0 ; i < V ; i++) {
		cout << " " << i << " | ";
		cout << (d[i] < 10 ? " " : "") << d[i] << " ";
        cout << (f[i] < 10 ? "  " : " ") << f[i] << " ";
        cout << (pred[i] < 0 ? " " : "  ") << pred[i] << "\n";
	}
}

int main() {
	int choice;
	do {
		cout << "===========MENU===========\n"
				"1) Input adjacency list\n"
				"2) DFS\n"
				"3) Exit\n"
				"Please choose > ";
		cin >> choice;
		switch(choice) {
			case 1:
				adjacency_list();
				break;
			case 2:
				int S;
				cout << "Enter source : ";
				cin >> S;
				depth_first_search(S);
				break;
			case 3:
				cout << "Exiting...";
				break;
			default:
				cout << "Invalid choice! Try again\n";
		}
	} while(choice != 3);
	
	return 0;
}

/*
vertex and Edge : 6 7
Edge : 0 1 
Edge : 0 3 
Edge : 1 4
Edge : 4 3
Edge : 2 4
Edge : 2 5
Edge : 5 5
*/