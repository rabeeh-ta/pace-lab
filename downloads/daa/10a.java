import java.util.Scanner;

class floyd {
    public static void main(String[] args) {
        int wt[][] = new int[10][10];
        int i, j, n;
        Scanner scan = new Scanner(System.in);

        System.out.println("\n create a graph using adjacency matrix");
        System.out.println("Enter the no of vertices");
        n = scan.nextInt();

        System.out.println("Enter the elements. 999 in infinity value");
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                wt[i][j] = scan.nextInt();
        }

        System.out.println("Computing shortest path");
        floyd_shortest_path(wt, n);

    }

    public static void floyd_shortest_path(int wt[][], int n) {
        int d[][] = new int[10][10];
        int i, j, k;

        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++)
                d[i][j] = wt[i][j];
        }

        for (k = 1; k <= n; k++) {
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], (d[i][k] + d[k][j]));
            }
        }

        for (k = 0; k <= n; k++) {
            System.out.println("d(" + k + ")\n");
            for (i = 1; i <= n; i++) {
                for (j = 1; j <= n; j++) {
                    System.out.print(" " + d[i][j]);
                }
                System.out.println(" ");
            }

        }

    }

    public static int min(int a, int b) {
        if (a < b)
            return a;
        else
            return b;
    }
}