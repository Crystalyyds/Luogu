import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        ArrayList<Integer> arr = new ArrayList<Integer>();
        while (n-- != 0) {
            int a = scanner.nextInt();
            arr.add(a);
        }
        int m = scanner.nextInt();
        while (m-- != 0) {
            int op = scanner.nextInt();
            if (op == 1) {
                int y = scanner.nextInt();
                int z = scanner.nextInt();
                arr.add(y, z);
            } else if (op == 2) {
                int y = scanner.nextInt();
                arr.remove(y);
            } else if (op == 3) {
                int y = scanner.nextInt();
                int z = scanner.nextInt();
                arr.set(y, z);
            } else if (op == 4) {
                int y = scanner.nextInt();
                System.out.println(arr.get(y));
                continue;
            }
            for (int i = 0; i < arr.size(); i++) {
                System.out.print(arr.get(i));
                if (i != arr.size() - 1) {
                    System.out.print(" ");
                }
            }
            System.out.println();
        }
        scanner.close();
    }
}