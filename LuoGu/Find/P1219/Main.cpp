#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/93736574
int n, num;
int a[100], b[100], c[100], d[100];
void sout() {
  if (num <= 3) {
    for (int i = 1; i <= n; i++) {
      cout << a[i] << " ";
    }
    cout << endl;
  }
}

void fun(int i) {
  for (int j = 1; j <= n; j++) {
    if (b[j] == 0 && c[i + j] == 0 && d[i - j + n] == 0) {
      a[i] = j;
      b[j] = 1;
      c[i + j] = 1;
      d[i - j + n] = 1;
      if (i == n) {
        num++;
        sout();
      } else
        fun(i + 1);
      b[j] = 0;
      c[i + j] = 0;
      d[i - j + n] = 0;
    }
  }
}
int main() {
  cin >> n;
  fun(1);
  cout << num << endl;
  return 0;
}