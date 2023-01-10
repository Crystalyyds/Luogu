package school.day4.C;

import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            char op = scanner.next().charAt(0);
            int ww = scanner.nextInt();

            if (list.size() == 0) {
                list.add(ww);
                continue;
            }
            if (op == 'L') {
                list.add(0, ww);
            }
            if (op == 'R') {
                list.add(ww);
            }
            if (op == '?') {
                int ad = list.indexOf(ww) + 1;
                if (list.size() == 1) {
                    System.out.println(1);
                } else {
                    if (list.size() - ad < ad - 1) {
                        System.out.println(list.size() - ad);
                    } else {
                        System.out.println(ad - 1);
                    }
                }
            }
        }
    }
}