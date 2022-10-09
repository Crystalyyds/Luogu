package Demo7.P1591;

//https://www.luogu.com.cn/record/88912608
import java.math.BigInteger;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int m = scanner.nextInt();
        for (int i = 1; i <= m; i++) {
            BigInteger n = scanner.nextBigInteger();
            BigInteger cnt = new BigInteger("1");
            BigInteger a = new BigInteger("1");
            BigInteger b = new BigInteger("-1");
            int num = 0;
            int k = scanner.nextInt();
            while (n.compareTo(a) == 1 || n.compareTo(a) == 0) {
                cnt = cnt.multiply(n);
                n = n.add(b);
            }
            char[] arr = cnt.toString().toCharArray();

            for (char x : arr) {
                if (x == (char) k + 48) {
                    num++;
                }
            }
            System.out.println(num);
        }
        scanner.close();
    }
}