import java.util.Scanner;

public class Prims {
    public int cost[][] = new int[10][10];
    public int isVisited[] = new int[10];
    public int minCost;

    public void calc(int n) {
        int i, j, min = 999, num_edges = 1, a = 1, b = 1, minpos_i = 1, minpos_j = 1;

        while (num_edges < n) {
            for (i = 1, min = 999; i <= n; i++)
                for (j = 1; j <= n; j++)
                    if (this.cost[i][j] < min) {
                        if (this.isVisited[i] != 0) {
                            min = this.cost[i][j];
                            a = minpos_i = i;
                            b = minpos_j = j;
                        }
                    }

            if (this.isVisited[minpos_i] == 0 || this.isVisited[minpos_j] == 0) {
                System.out.println("\t from Vertex " + a + " to Vertex " + b + " mincost:" + min + " \n");
                this.minCost = this.minCost + min;
                num_edges = num_edges + 1;
                this.isVisited[b] = 1;
            }
            this.cost[a][b] = this.cost[b][a] = 999;
        }
        System.out.println("MINIMUM COST SPANNING TREE " + this.minCost);
    }

    public static void main(String[] args) {
        int i, j, n;
        Scanner scan = new Scanner(System.in);
        Prims p = new Prims();

        System.out.println("Enter the number of nodes");
        n = scan.nextInt();

        System.out.println("Enter the cost matrix weights");
        for (i = 1; i <= n; i++) {
            for (j = 1; j <= n; j++) {
                p.cost[i][j] = scan.nextInt();
                if (p.cost[i][j] == 0)
                    p.cost[i][j] = 999;
            }
            p.isVisited[1] = 1;
        }
        p.calc(n);

    }
}
