import java.util.Scanner;

public class TSP {
    static int cost = 0;

    public static void main(String[] args) {
        int a[][] = new int[10][10];
        int visited[] = new int[10];
        int i, j, n;
        System.out.print("\n eneter no of cities");
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        System.out.println("enter cost matrix");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                a[i][j] = in.nextInt();
            }
            visited[i] = 0;
        }
        System.out.println("The Path is");
        mincost(a, n, 0, visited);
        display();
    }

    public static void mincost(int a[][], int n, int city, int visited[]) {
        int i, cityno;
        visited[city] = 1;
        System.out.print((city + 1) + "->");
        cityno = least(a, visited, n, city);
        if (cityno == 999) {
            cityno = 0;
            System.out.print("" + (cityno + 1));
            cost += a[city][cityno];
            return;
        }
        mincost(a, n, cityno, visited);
    }

    public static int least(int a[][], int visited[], int n, int c) {
        int i, minnode = 999, min = 999, newmin = 0;
        for (i = 0; i <= n; i++) {
            if ((a[c][i] != 0) && (visited[i] == 0))
                if (a[c][i] < min) {
                    min = a[i][0] + a[c][i];
                    newmin = a[c][i];
                    minnode = i;
                }
        }
        if (min != 999)
            cost += newmin;
        return minnode;
    }

    public static void display() {
        System.out.println("\n total cost of tour " + cost);
    }
}