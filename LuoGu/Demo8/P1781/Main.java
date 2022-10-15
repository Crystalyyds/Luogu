import java.math.BigInteger;
import java.util.Scanner;

//https://www.luogu.com.cn/record/89659144
public class Main {
    static Scanner scanner = new Scanner(System.in);

    public static void main(String[] args) {
        int n = scanner.nextInt();
        int index = 0;
        BigInteger att = new BigInteger("0");
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            BigInteger temp = scanner.nextBigInteger();
            if (temp.compareTo(att) == 1) {
                att = temp;
                index = j;
            }
        }
        System.out.println(index);
        System.out.println(att);
    }
}
