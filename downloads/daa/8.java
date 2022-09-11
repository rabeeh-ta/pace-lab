import java.util.Scanner;

public class Kruskals {
    public int cost[][] = new int[10][10];
    public int parent[] = new int[10];
    public int minCost;

    public void calc(int n) {
        int i, j, min = 999, num_edges = 1, a = 1, b = 1, minpos_i = 1, minpos_j = 1;
        parent[minpos_i] = 0;
        parent[minpos_j] = 0;
        while (num_edges < n) {
            for (i = 1, min = 999; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (this.cost[i][j] < min) {
                        min = this.cost[i][j];
                        a = minpos_i = i;
                        b = minpos_j = j;
                    }
            while (parent[minpos_i] != 0)
                minpos_i = parent[minpos_i];
            while (parent[minpos_j] != 0)
                minpos_j = parent[minpos_j];
            if (minpos_i != minpos_j) {
                System.out.println("\t from Vertex " + a + " to Vertex " + b + " mincost:" + min + " \n");
                this.minCost = this.minCost + min;
                num_edges = num_edges + 1;
                this.parent[minpos_j] = minpos_i;
            }
            this.cost[a][b] = this.cost[b][a] = 999;
        }
        System.out.println("MINIMUM COST SPANNING TREE " + this.minCost);
    }

    public static void main(String[] args) {
        int i, j, n;
        Scanner scan = new Scanner(System.in);
        Kruskals k = new Kruskals();

        System.out.println("Enter the number of nodes");
        n = scan.nextInt();

        System.out.println("Enter the cost matrix weights");
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                k.cost[i][j] = scan.nextInt();
                if (k.cost[i][j] == 0)
                    k.cost[i][j] = 999;
            }
        }
        k.calc(n);

    }
}
