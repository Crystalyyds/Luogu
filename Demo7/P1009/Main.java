package Demo7.P1009;

import java.math.BigDecimal;
import java.util.Scanner;

//https://www.luogu.com.cn/record/88732495
public class Main {
    public static void main(String[] args) {
        BigDecimal temp = new BigDecimal(1);
        BigDecimal cnt = new BigDecimal(0);
        BigDecimal a = new BigDecimal(1);
        BigDecimal b = new BigDecimal(1);
        Scanner scanner = new Scanner(System.in);
        BigDecimal n = scanner.nextBigDecimal();
        while (n.compareTo(a) == 1 || n.compareTo(a) == 0) {
            temp = temp.multiply(a);
            cnt = cnt.add(temp);
            a = a.add(b);
        }
        scanner.close();
        System.out.println(cnt);
    }

}
