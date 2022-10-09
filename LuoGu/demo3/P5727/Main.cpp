#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87453388
int main() {
  int n, num = 0, count = 0;
  scanf("%d", &n);
  int temp = n;
  int array[1002];
  while (n != 1) {
    if (n % 2 == 0) {
      n = n / 2;
      array[num++] = n;
    } else {
      n = n * 3 + 1;
      array[num++] = n;
    }
    count++;
  }
  for (int i = num - 1; i >= 0; i--) {
    cout << array[i] << " ";
  }
  cout << temp << " ";
}