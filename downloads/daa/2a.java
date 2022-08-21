package com.example.twoa;

import java.util.Scanner;

public class Staff {
    private String staffId;
    private String name;
    private long phone;
    private int salary;

    void accept(){
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter the Staffid");
        staffId = scan.next();
        System.out.println("Enter the Name");
        name = scan.next();
        System.out.println("Enter the Phone");
        phone = scan.nextLong();
        System.out.println("Enter the Salary");
        salary = scan.nextInt();
    }

    public void display(){
        System.out.println("Staff Id: " + staffId);
        System.out.println("Name: " + name);
        System.out.println("Phone: " + phone);
        System.out.println("Salary: " + salary);
    }
}

class Teaching extends Staff{
    private String domain ;
    private String[] publications;

    public void accept(){
        super.accept();
        Scanner scan = new Scanner(System.in);

        System.out.println("enter the domain");
        domain = scan.next();
        System.out.println("Enter the number of publication");
        int n = scan.nextInt();
        publications = new String[n];

        System.out.println("Enter the Publications");
        for(int i = 0; i<n ; i++){
            publications[i] = scan.next();
        }
    }

    public void display(){
        super.display();
        System.out.println("domain: " + domain);
        for ( int i = 0; i<publications.length;i++){
            System.out.println(publications[i]);
        }
    }
}

class Technical extends Staff{
    private String[] skills ;

    public void accept(){
        super.accept();
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter the number of skills");
        int n = scan.nextInt();
        skills = new String[n];


        System.out.println("Enter the skills");
        for(int i = 0; i<n ; i++){
            skills[i] = scan.next();
        }
    }

    public void display(){
        super.display();
        System.out.println("Skills: ");
        for ( int i = 0; i<skills.length;i++){
            System.out.println(skills[i]);
        }
    }
}

class Contract extends Staff{
    private int period ;

    public void accept(){
        super.accept();
        Scanner scan = new Scanner(System.in);

        System.out.println("Enter Time period");
        period = scan.nextInt();
    }

    public void display(){
        super.display();
        System.out.println("Period: "+ period);
    }
}

class Main{
    public static void main(String[] args) {
        Teaching teaching = new Teaching();
        Technical technical = new Technical();
        Contract contract = new Contract();

        System.out.println("Enter the details for Teaching Staff");
        teaching.accept();
        System.out.println("Enter the details for Technical Staff");
        technical.accept();
        System.out.println("Enter the details for contract Staff");
        contract.accept();

        System.out.println("Details for Teaching Staff");
        teaching.display();
        System.out.println("Details for Technical Staff");
        technical.display();
        System.out.println("Details for Contract Staff");
        contract.display();
    }
}


