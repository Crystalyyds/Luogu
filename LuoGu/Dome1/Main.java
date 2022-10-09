import java.util.Scanner;

//no11
public class Main {
    public static void main(String[] args) {
        int f = 0, g = 0;
        int d = 8;
        int e = 0;
        Scanner scanner = new Scanner(System.in);
        double a = scanner.nextInt();
        double b = scanner.nextInt();
        double c = a / b;
        if (c % 1 != 0) {
            c = c / 1 + 1;
        }
        if (e - c < 0) {
            f = (int) Math.abs(e - c) / 60;

            g = (int) Math.abs(e - c) % 60;

        }
        d = d - f;
        e = e - g;
        if (e < 0) {
            if (e < 0 && e > -60) {
                d = d - 1;
                e = 60 + e;
            } else {
                d = d - Math.abs(e / 60);
                e = 60 + (e % 60);
            }
        }
        if (d < 10) {
            System.out.print("0" + Math.abs(d) + ":");
        }
        if (d > 10) {
            System.out.print(d + ":");
        }
        if (e < 10) {
            System.out.print("0" + e);
        }
        if (e > 10) {
            System.out.print(e);
        }
        scanner.close();
    }
}