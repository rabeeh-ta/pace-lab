import java.util.Random;
import java.util.Scanner;

public class Merge {
    private int[] numbers;
    private int[] c;

    private int number;

    public void sort(int[] values) {
        if (values == null || values.length == 0)
            return;

        this.numbers = values;
        number = values.length;
        this.c = new int[number];

        mergesort(0, number - 1);
    }

    public void mergesort(int low, int high) {
        if (low < high) {
            int mid = (low + high) / 2;

            mergesort(low, mid);
            mergesort(mid + 1, high);
            mergearray(low, mid, high);
        }
    }

    public void mergearray(int low, int mid, int high) {
        int i = low;
        int j = mid + 1;
        int k = low;

        while (i < mid && j < high) {
            if (numbers[i] < numbers[j])
                c[k++] = numbers[i++];
            else
                c[k++] = numbers[j++];
        }

        while (i <= mid)
            c[k++] = numbers[i++];
        while (j <= high)
            c[k++] = numbers[j++];

        for (i = low; i <= high; i++)
            numbers[i] = c[i];
    }

    public static void main(String[] args) {
        Merge sorter = new Merge();
        int[] numbers;
        int number;
        int[] c;

        Scanner scan = new Scanner(System.in);

        System.out.println("Enter size of the array");
        number = scan.nextInt();

        numbers = new int[number];

        System.out.println("The elements of the array");
        Random random = new Random();

        for (int i = 0; i < number; i++)
            numbers[i] = Math.abs(random.nextInt(5000));

        for (int i = 0; i < number; i++)
            System.out.print("\t" + numbers[i]);
        System.out.println();

        long statTime = System.currentTimeMillis();
        sorter.sort(numbers);
        long stopTime = System.currentTimeMillis();
        long elapsedTime = stopTime - statTime;

        System.out.println("sorted array is");
        for (int i : numbers)
            System.out.print("\t" + i);

        System.out.println();
        System.out.println("time taken " + elapsedTime);

    }

}
