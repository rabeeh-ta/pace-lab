import java.util.Scanner;

public class Student {
    long USN;
    String Name;
    String Branch;
    long Phone;

    public Student(long usn, String name, String br, long ph) {
        this.USN = usn;
        this.Name = name;
        this.Branch = br;
        this.Phone = ph;
    }

    void display() {
        System.out.println(USN + "\t" + Name + "\t" + Branch + "\t" + Phone);
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the number of students");
        int n = scan.nextInt();

        Student[] students = new Student[n];

        for (int i = 0; i < n; i++) {
            System.out.println("Enter the details of student" + (i + 1));

            System.out.println("Enter the USN");
            long usn = scan.nextLong();

            System.out.println("Enter the name of the student");
            String name = scan.next();

            System.out.println("Enter the name of the branch");
            String branch = scan.next();

            System.out.println("Enter the phone number");
            long phone = scan.nextLong();

            students[i] = new Student(usn, name, branch, phone);
        }

        System.out.println("USN" + "\t" + "Name" + "\t" + "Branch" + "\t" + "Phone");
        for (int i = 0; i < n; i++) {
            students[i].display();
        }
    }
}
