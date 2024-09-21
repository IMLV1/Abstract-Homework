#include <iostream>
#include <vector>
#define MAX 6
using namespace std;

vector<int> adjList[MAX];
vector<int> transposeList[MAX];

int pass[MAX];
int pred[MAX];
int d[MAX];
int f[MAX];
int degree[MAX];
int	degreeT[MAX];
int time = 0;
int V, E;
int u, v;

void print_adjacency_list() {
	cout << "ADJACENCY LIST\n";
	for (int i = 0; i < V; i++) {
		cout << i << " : ";
		for (int j = 0; j < degree[i]; j++) {
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
		transposeList[v].push_back(u);
		degreeT[v]++;
		degree[u]++;
	}
	print_adjacency_list();
}

void print_transpose_list() {
	cout << "Transpose Graph\n";
	for (int i = 0; i < V ; i++) {
		cout << i << " : ";
		for (int j = 0; j < degreeT[i]; j++) {
			cout << transposeList[i][j] << " ";
		}
		cout << "\n";
	}
}

int main() {
	int choice;
	do {
		cout << "===========MENU===========\n"
				"1) Input adjacency list\n"
				"2) Transpose\n"
				"3) Exit\n"
				"Please choose > ";
		cin >> choice;
		switch(choice) {
			case 1:
				adjacency_list();
				break;
			case 2:
				print_transpose_list();
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
