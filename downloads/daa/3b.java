import java.util.Random;

class Cube implements Runnable {
    public int x;

    public Cube(int x) {
        this.x = x;
    }

    @Override
    public void run() {
        System.out.println("Cube: " + x * x * x);
    }
}

class Square implements Runnable {
    public int x;

    public Square(int x) {
        this.x = x;
    }

    @Override
    public void run() {
        System.out.println("Square: " + x * x);
    }
}

class FirstThreadRandom extends Thread {
    public void run() {
        int num = 0;
        Random r = new Random();

        try {
            for (int i = 0; i < 5; i++) {
                num = r.nextInt(100);
                System.out.println("Main Thread Started and generated Number: " + num);

                Thread t2 = new Thread(new Square(num));
                t2.start();

                Thread t3 = new Thread(new Cube(num));
                t3.start();

                Thread.sleep(1000);
            }
        } catch (InterruptedException e) {
            System.out.println(e.getMessage());
        }
    }
}

public class MultiThread {
    public static void main(String[] args) {
        FirstThreadRandom ft = new FirstThreadRandom();
        Thread t1 = new Thread(ft);

        t1.start();
    }

}
