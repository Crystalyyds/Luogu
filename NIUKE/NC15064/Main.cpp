#include <bits/stdc++.h>
using namespace std;
int digit;
int main() {
  int i, j, k;
  int N;
  while (~scanf("%d/n", &N)) {
    int a[50000];             //用数组存值，阶乘的值为大数
    memset(a, 0, sizeof(a));  //数组初始化
    a[0] = 1;
    int digit = 1;  // 结果的位数
    int up = 0;     //进位
    int temp;
    for (i = 2; i <= N; i++)  //求阶乘
    {
      for (j = 0; j < digit;
           j++)  //当前值的每一位乘阶乘的数，例如13*8->3*8->1*8+2
      {
        temp = a[j] * i + up;
        a[j] = temp % 10;
        up = temp / 10;
      }
      while (up)  //如果最高位有进位，将最高位存入
      {
        a[digit] = up % 10;
        up = up / 10;
        digit++;
      }
    }
    for (i = digit - 1; i >= 0; i--) {
      printf("%d", a[i]);
    }
    printf("\n");
  }
}