package Demo7.P1045;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        BigInteger cnt = new BigInteger("1");
        BigInteger a = new BigInteger("2");
        BigInteger b = new BigInteger("-1");
        while (n-- >= 1) {
            cnt = cnt.multiply(a);
        }
        cnt = cnt.add(b);
        String str = cnt.toString();
        char[] arr = str.toCharArray();
        System.out.println(str.length());
        if (str.length() >= 500) {
            for (int i = 0; i < 500; i++) {
                System.out.print(arr[i]);
                if (i % 50 == 0) {
                    System.out.println();
                }
            }
        } else {
            for (int i = 1; i <= 500 - str.length(); i++) {
                System.out.print(0);
                if (i % 50 == 0) {
                    System.out.println();
                }
            }
            for (int j = 1; j <= str.length(); j++) {
                System.out.print(arr[j - 1]);
                if ((j + 500 - str.length()) % 50 == 0) {
                    System.out.println();
                }
            }
        }
        scanner.close();
    }
}
