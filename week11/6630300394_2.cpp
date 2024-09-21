#include <iostream>
#include <vector>
#define MAX 8 
using namespace std;             

vector<int> adjList[MAX];
vector<int> topological;
string strArr[MAX];

int pass[MAX];
int pred[MAX];
int d[MAX];
int f[MAX];
int degree[MAX];
int time = 0;
int V, E;
int u, v;

void inputName() {
    for (int i = 0; i < MAX; i++) {
        cout << "Enter name #" << i << " : ";
        cin >> strArr[i];
    }
}

void inputGraph() {
    cout << "Enter vertex and Edge : ";
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        cout << "Enter : ";
        cin >> u >> v;
        degree[u]++;
        adjList[u].push_back(v);
    }
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
	topological.push_back(u);
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
}

void topologicalSort(int s) {
	topological.clear();
	depth_first_search(s);
	cout << "Topological sort\n"
			"================\n";
	for (int i = topological.size() - 1; i >= 0; i--) {
        cout << strArr[topological[i]] << "\n";
    }
}

int main() {
    int choice, s = 0;
    do {
        cout << "===========MENU===========\n"
                "1) Input name\n"
                "2) Input Graph\n"
                "3) Topological sort\n"
                "4) Exit\n"
                "Please choose > ";
        cin >> choice;
        switch(choice) {
            case 1:
                inputName();
                break;
            case 2:
                inputGraph();
                break;
            case 3:
                topologicalSort(s); 
                break;
            default:
                cout << "Invalid choice! Try again\n";
        }
    } while(choice != 4);

    return 0;
}

/*
Vertex
0: FUND1
1: ADT
2: ALGOR
3: DISCRETE
4: MATH1
5: MATH2
6: MATH3
7: PROB
*/

/* 
vertex and Edge : 8 6
Edge : 0 1 
Edge : 1 2
Edge : 3 2
Edge : 4 5
Edge : 5 6
Edge : 5 7
*/