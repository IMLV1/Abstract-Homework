#include <iostream>
using namespace std;

struct node {
    int value;
    int height;
    struct node *left;
    struct node *right;
};

int fheight(struct node *tree) {
    if (tree == NULL) {
        return -1;
    } else {
        return tree -> height;
    }
}

int Max(int data1, int data2) {
    return (data1 >= data2) ? data1 : data2;
}

struct node *srleft(struct node *k2) {
    struct node *k1 = k2 -> left;
    k2 -> left = k1 -> right;
    k1 -> right = k2;
    
    k2 -> height = Max(fheight(k2 -> left), fheight(k2 -> right)) + 1;
    k1 -> height = Max(fheight(k1 -> left), k2 -> height) + 1;   
    return k1;
}

struct node *srright(struct node *k2) {
    struct node *k1 = k2 -> right;
    k2 -> right = k1 -> left;
    k1 -> left = k2;
    
    k2 -> height = Max(fheight(k2 -> left), fheight(k2 -> right)) + 1;
    k1 -> height = Max(fheight(k1 -> right), k2 -> height) + 1;  
    return k1;
}

struct node *drleft(struct node *k3) {
    k3 -> left = srright(k3 -> left);
    return srleft(k3);
}

struct node *drright(struct node *k3) {
    k3 -> right = srleft(k3 -> right);
    return srright(k3);
}

struct node *insert(struct node *tree, int data) {
    if (tree == NULL) {
        tree = new struct node;
        tree -> value = data;
        tree -> height = 0;
        tree -> left = tree -> right = NULL;  
    } else {
        if (data < tree -> value) {
            tree -> left = insert(tree -> left, data);
            if (fheight(tree -> left) - fheight(tree -> right) == 2) {
                if (data < tree -> left -> value) {
                    tree = srleft(tree);  
                } else {
                    tree = drleft(tree);  
                }
            }
        } else if (data > tree -> value) {
            tree->right = insert(tree -> right, data);
            if (fheight(tree -> right) - fheight(tree -> left) == 2) {
                if (data > tree -> right -> value) {
                    tree = srright(tree); 
                } else {
                    tree = drright(tree);  
                }
            }
        }
    }
    
    tree -> height = Max(fheight(tree -> left), fheight(tree -> right)) + 1;
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

int main() {
    struct node *tree = NULL;
    int data;
    
    while (true) {
        cout << "========MENU======\n"
                "1) Insert\n"
                "2) Print Inorder, Min, Max\n"
                "3) Print Leave node (Inorder)\n"
                "4) Exit\n"
                "Please choose > ";
        cin >> data;
        switch (data) {
            case 1:
                cout << "Enter : ";
                cin >> data;
                tree = insert(tree, data);
                cout << "Success!\n";
                break;
            case 2:
                if (tree == NULL) {
                    cout << "No data in tree\n";
                } else {
                    cout << "Inorder : ";
                    printInorder(tree);
                    cout << "\nMin : " << findMin(tree) -> value << endl;
                    cout << "Max : " << findMax(tree) -> value << endl;
                }
                break;
            case 3:
                if (tree == NULL) {
                    cout << "No data in tree";
                } else {
                    cout << "Leaves : ";
                    printleave(tree);
                }
                cout << endl;
                break;
            case 4:
                cout << "Exiting...";
                return 0;
            default:
                cout << "Please Select 1-4!\n";
        }
    }
}
