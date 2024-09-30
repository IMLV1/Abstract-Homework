class Node {
    int value;
    Node left;
    Node right;

    public Node(int data) {
        this.value = data;
        left = null;
        right = null;
    }
}

public class BinaryTree {

    Node tree;

    public void insert(int data) {
        tree = insertRec(tree, data);
    }

    public Node insertRec(Node tree, int data) {
        if (tree == null) {
            tree = new Node(data);
        } else if (data < tree.value) {
            tree.left = insertRec(tree.left, data);
        } else if (data > tree.value) {
            tree.right = insertRec(tree.right, data);
        }
        return tree;
    }

    public void inorder() {
        System.out.print("Inorder : ");
        inorderRec(tree);
        System.out.println();
    }

    public void inorderRec(Node tree) {
        if (tree != null) {
            inorderRec(tree.left);
            System.out.print(tree.value + " ");
            inorderRec(tree.right);
        }
    }

    public void delete(int data) {
        tree = deleteRec(tree, data);
    }

    public Node deleteRec(Node tree, int data) {
        if (tree == null) {
            return null;
        }
        if (data < tree.value) {
            tree.left = deleteRec(tree.left, data);
        } else if (data > tree.value) {
            tree.right = deleteRec(tree.right, data);
        } else {
            if (tree.left == null && tree.right == null) {
                return null;
            } else if (tree.left == null) {
                return tree.right;
            }else if (tree.right == null) {
                return tree.left;    
            } else {
                Node minNode = find_min(tree.right);
                tree.value = minNode.value;
                tree.right = deleteRec(tree.right, tree.value);
            }
        }
        return tree;
    }

    public Node find_min(Node tree) {
        if (tree == null) {
            return null; 
        }
        return (tree.left == null) ? tree : find_min(tree.left); 
    }

    public Node find_max(Node tree) { 
        if (tree == null) {
            return null; 
        }
        return (tree.right == null) ? tree : find_max(tree.right); 
    }

    public void get_min() {
        Node minNode = find_min(tree);
        if (minNode != null) {
            System.out.println("Min = " + minNode.value);
        } else {
            System.out.println("Tree Empty.");
        }
    }

    public void get_max() { 
        Node maxNode = find_max(tree);
        if (maxNode != null) {
            System.out.println("Max = " + maxNode.value);
        } else {
            System.out.println("Tree Empty.");
        }
    }

    public void leave() {
        System.out.println("Leaves : ");
        get_leave(tree);
        System.out.println();
    }

    public void get_leave(Node tree) {
        if (tree != null) {
            get_leave(tree.left);
            if (tree.left == null && tree.right == null) {
                System.out.print(tree.value + " ");
            }
            get_leave(tree.right);
        }
    }

    public void Non_leave() {
        System.out.println("Leaves : ");
        get_leave(tree);
        System.out.println();
    }

    public void get_nonleave(Node tree) {
        if (tree != null) {
            get_nonleave(tree.left);
            if (tree.left != null || tree.right != null) {
                System.out.print(tree.value + " ");
            }
            get_nonleave(tree.right);
        }
    }
}