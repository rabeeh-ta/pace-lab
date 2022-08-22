import java.util.Scanner;
import java.util.StringTokenizer;

public class Customer {
    private String customer;
    private String date;

    public Customer(String customer, String date) {
        this.customer = customer;
        this.date = date;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the name of the customer ");
        String customerName = scan.next();
        System.out.println("Date(dd/mm/yyyy)");
        String dateOFBirth = scan.next();

        Customer customer = new Customer(customerName, dateOFBirth);
        System.out.println("Customer Name " + customerName);
        StringTokenizer date = new StringTokenizer(dateOFBirth, "/");

        System.out.println("Customer DOB: " + date.nextToken() + "," + date.nextToken() + "," + date.nextToken());
    }
}
