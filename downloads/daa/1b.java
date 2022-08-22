import java.util.Scanner;

public class Stack {
    private static final int max_size = 5;

    int[] arr = new int[max_size];
    int top = -1;

    public void push(int ele) {
        if (top < max_size - 1) {
            System.out.println("the element added is " + ele);
            top++;
            arr[top] = ele;
        } else {
            System.out.println("Error: StackOverflow");
        }
    }

    public void pop() {
        if (top >= 0) {
            System.out.println("the element poped is " + arr[top]);
            top--;
        } else {
            System.out.println("Error: Stack underflow");
        }
    }

    public void display_stack_contents() {
        if (top >= 0) {
            for (int i = 0; i <= top; i++) {
                System.out.println(arr[i] + " ");
            }
        } else {
            System.out.println("stack is empty");
        }
    }

    public static void main(String[] args) {
        Stack stack = new Stack();
        Scanner scan = new Scanner(System.in);

        int elem;
        boolean whileLoop = true;

        do {
            System.out.println("Enter your choice: \n 1.push \n 2.pop \n 3.dispaly \n 4.exit \n");
            int choice = scan.nextInt();

            switch (choice) {
                case 1:
                    System.out.println("Enter the element to be inserted \n");
                    elem = scan.nextInt();
                    stack.push(elem);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.display_stack_contents();
                    break;
                case 4:
                    whileLoop = false;
                    break;
                default:
                    System.out.println("invalid input");
            }
        } while (whileLoop);
    }
}
