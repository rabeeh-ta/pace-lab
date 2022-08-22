import java.util.Scanner;

public class GreedyKnapsack {

    static void knapsack(int n, float weight[], float profit[], float capacity) {
        float x[] = new float[20], tp = 0;
        int i, j, u;
        c = (int) capacity;
        for (i = 0; i < n; i++)
            x[i] = (float) 0.0;
        for (i = 0; i < n; i++) {
            if (weight[i] > c)
                break;
            else {
                x[i] = (float) 1.0;
                tp = tp + profit[i];
                c = (int) (c - weight[i]);
            }
        }
        if (i < n)
            x[i] = c / weight[i];
        tp = tp + (x[i] * profit[i]);
        System.out.println("the result vector");
        for (i = 0; i < n; i++)
            System.out.println(+x[i]);
        System.out.println("the total profit is");
        System.out.println(+tp);
    }

    public static void main(String[] args) {
        float weight[] = new float[20];
        float profit[] = new float[20];
        float capacity;
        int num, i, j;
        float ratio[] = new float[20], temp;
        System.out.println("\nenter the no of objects");
        Scanner s = new Scanner(System.in);
        num = s.nextInt();
        System.out.println("\n enter weights and profit of each object");
        for (i = 0; i < num; i++) {
            weight[i] = s.nextInt();
            profit[i] = s.nextInt();
        }
        System.out.println("\ncapacity of knapsack");
        capacity = s.nextInt();
        for (i = 0; i < num; i++) {
            ratio[i] = profit[i] / weight[i];
        }
        for (i = 0; i < num; i++) {
            for (j = i + 1; j < num; j++) {
                if (ratio[i] < ratio[j]) {
                    temp = ratio[j];
                    ratio[j] = ratio[i];
                    ratio[i] = temp;
                    temp = weight[j];
                    weight[j] = weight[i];
                    weight[i] = temp;
                    temp = profit[j];
                    profit[j] = profit[i];
                    profit[i] = temp;
                }
            }
        }
        knapsack(num, weight, profit, capacity);
    }
}
