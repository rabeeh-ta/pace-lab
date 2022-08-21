package Three;

import java.util.Scanner;

public class Divide {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the integers A and B");
        int a = scan.nextInt();
        int b = scan.nextInt();

        try{
            System.out.println("The result of division a / b is " + (a/b));
        }
        catch ( ArithmeticException e){
            System.out.println("division by zero error");
        }
    }
}
