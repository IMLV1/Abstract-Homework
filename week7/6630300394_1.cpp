#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;
};

int display() {
	int select;
	cout << "========MENU======\n 1) Insert\n 2) Print Inorder, Postorder, Max to min\n 3) Exit\n    Please choose > ";
	cin >> select;
	return select;
}

struct node *insert(struct node *tree, int data) {
	if (tree == NULL) {
		tree = new struct node;
		tree -> value = data;
		tree -> left = tree -> right = NULL;
	} else {
		if (data < tree -> value) {
			tree -> left = insert(tree -> left, data);
		} else if (data > tree -> value) {
			tree -> right = insert(tree -> right, data);
		}
	}
	
	return tree;
} 

void printPreorder(struct node *tree) {
	if (tree == NULL) return;
	else {
		// (Root, Left, Right)
		cout << tree -> value << " ";
		printPreorder(tree -> left);
		printPreorder(tree -> right);
	}
	
	return;
}

void printInorder(struct node *tree) {
	if (tree == NULL) return;
	else {
		// (Left, Root, Right)
		printInorder(tree -> left);
		cout << tree -> value << " ";
		printInorder(tree -> right);
	}
	
	return;
}

void printPostorder(struct node *tree) {
	if (tree == NULL) return;
	else {
		// (Left, Right, Root)
		printPostorder(tree -> left);
		printPostorder(tree -> right);
		cout << tree -> value << " ";
	}
	
	return;
}

void printMaxtoMin(struct node *tree) {
	if (tree == NULL) return;
	else {
		// (Right, Root, Left)
		printMaxtoMin(tree -> right);
		cout << tree -> value << " ";
		printMaxtoMin(tree -> left);
	}
	
	return;
}

int main() {
	struct node *tree = NULL;
	int data;
	
	while(true) {
		switch(display()) {
			case 1:
				cout << "Enter : ";
				cin >> data;
				tree = insert(tree, data);
				cout << "Success!\n";
				break;
			case 2:
				if (tree != NULL) {
					cout << "Preorder   : ";
					printPreorder(tree);
					cout << "\nInorder    : ";
					printInorder(tree);
					cout << "\nPostorder  : ";
					printPostorder(tree);
					cout << "\nMax to min : ";
					printMaxtoMin(tree);
				} else {
					cout << "No Data to Print";
				}		
				cout << endl;
				break;
			case 3:
				cout << "Exiting...";
				return 0;
			default:
				cout << "Please select 1 - 3\n";
				break;
		}
	}
}