package Demo7.P1601;

import java.util.Scanner;

import java.math.BigInteger;

//https://www.luogu.com.cn/record/88719639
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        BigInteger a = scanner.nextBigInteger();
        BigInteger b = scanner.nextBigInteger();
        System.out.println(a.add(b));
        scanner.close();
    }
}