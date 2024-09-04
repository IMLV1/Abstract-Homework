#include <iostream>
using namespace std;

struct node {
	int value;
	struct node *left;
	struct node *right;	
};

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

struct node *findMin(struct node *tree) {
	if (tree == NULL) {
		return NULL;
	} else {
		if (tree -> left == NULL) {
			return tree;
		} else {
			return findMin(tree -> left);
		}
	}
}

struct node *findMax(struct node *tree) {
	if (tree == NULL) {
		return NULL;
	} else {
		if (tree -> right == NULL) {
			return tree;
		} else {
			return findMax(tree -> right);
		}
	}
}

struct node *deltree(struct node *tree, int data) {
	if (tree == NULL) {
		return tree;
	} 
	
	if (data < tree -> value) {
		tree -> left = deltree(tree -> left, data);
	} else if (data > tree -> value) {
		tree -> right = deltree(tree -> right, data);
	} else {
		if (tree -> left != NULL && tree -> right != NULL) {
			tree -> value = findMin(tree -> right) -> value;
			tree -> right = deltree(tree -> right,tree -> value);
		} else {
			struct node *tmp = tree;
			struct node *child;
			if (tree -> left == NULL) {
				child = tree -> right;
			}
			if (tree -> right == NULL) {
				child = tree -> left;
			}
			
			delete tmp;
			return child;
		}
	}
	
	return tree;
}

void printInorder(struct node *tree) {
	if (tree == NULL) {
		return;
	} else {
		printInorder(tree -> left);
		cout << tree -> value << " ";
		printInorder(tree -> right);
	}
	
	return;
}

bool find(struct node* tree, int data) {
	if (tree == NULL) {
		return false;
	} else {
		if (tree -> value == data) {
			return true;
		} else {
			if (data < tree -> value) {
				return find(tree -> left, data);
			} else {
				return find(tree -> right, data);
			}
		}		
	}
}

void printleave(struct node *tree) {
	if (tree == NULL) {
		return;
	} else {
		printleave(tree -> left);
		if (tree -> left == NULL && tree -> right == NULL) {
			cout << tree -> value << " ";
		}
		printleave(tree -> right);	
	}
	
	return;
}

void printNonleave(struct node *tree) {
	if (tree == NULL) {
		return;
	} else {
		printNonleave(tree -> left);
		if (tree -> left != NULL || tree -> right != NULL) {
			cout << tree -> value << " ";
		}
		printNonleave(tree -> right);	
	}
	
	return;
}


int main () {
	struct node *tree = NULL;
	int data, select;
	while(true) {
		cout << "========MENU======\n1) Insert\n2) Delete\n3) Print Inorder, max, min\n4) Print leave node, non leave node\n5) Exit\nPlease choose > ";
		cin >> select;
		switch(select) {
			case 1:
				cout << "Enter : ";
				cin >> data;
				tree = insert(tree, data);
				cout << "Success!\n";
				break;
			case 2:
				cout << "Delete : ";
				cin >> data;
				if (find(tree, data) == true) {
					tree = deltree(tree, data);
					if (tree == NULL) {
						cout << "No data in tree";
					} else {
						cout << "Data in tree = ";
						printInorder(tree);
					}
				} else {
					cout << "Can't delete number " << data << " from tree";
				}
	
				cout << endl;
				break;
			case 3:
				if (tree == NULL) {
					cout << "No data in tree\n";
				} else {
					cout << "Inorder : ";
					printInorder(tree);
					cout << "\nMax = " << findMax(tree) -> value << endl;
					cout << "Min = " << findMin(tree) -> value << endl;
				}
				break;
			case 4:
				if (tree == NULL) {
					cout << "No data in tree";
				} else {
					cout << "Leaves : ";
					printleave(tree);
					cout << "\nNonLeaves : ";
					printNonleave(tree);
				}
				cout << endl;
				break;
			case 5:
				cout << "Exiting...";
				return 0;
			default:
				cout << "Pease Select 1-5!\n";
		}
	}
}