import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        Scanner S = new Scanner(System.in);
        int select, data;
        do {
            System.out.println("========MENU======");
            System.out.println("1) Insert");
            System.out.println("2) Delete");
            System.out.println("3) Inorder, max, min");
            System.out.println("4) leave node, non leave node");
            System.out.println("5) Exit");
            System.out.print("Please select > ");
            select = S.nextInt();
            switch (select) {
                case 1:
                    System.out.print("Insert : ");
                    data = S.nextInt();
                    tree.insert(data);
                    break;
                case 2:
                    System.out.print("Delete : ");
                    data = S.nextInt();
                    tree.delete(data);
                    break;
                case 3:
                    tree.inorder();
                    tree.get_max(); 
                    tree.get_min();
                    break;
                case 4:
                    tree.leave();
                    tree.Non_leave();
                    break;
                case 5:
                    System.out.println("Exiting...");
                    break;
                default:
                    System.out.println("Invalid selection.");
                    break;
            }
        } while (select != 5);
        S.close();
    }
}
