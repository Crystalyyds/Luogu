#include <bits/stdc++.h>

using namespace std;
// https://ac.nowcoder.com/acm/problem/16622
int main() {
  int n;
  cin >> n;
  for (int i = n; i >= 0; i--) {
    int x;
    cin >> x;  // x是系数,i是指数
    if (x == 0) continue;

    if (x < 0)
      cout << "-";
    else if (i != n && x > 0)
      cout << "+";

    if (abs(x) == 1 && i != 0)
      ;
    else
      cout << abs(x);

    if (i > 1)
      cout << "x^" << i;
    else if (i == 1)
      cout << "x";
  }
}

// 1.先解决每一项的符号，即不输出、输出“+”或“-”，判断每一项的系数与0的关系即可。

// 2.再解决系数的问题，系数的绝对值为1时不需要输出，但指数为0时例外。

// 3.最后解决x格式的问题，分指数情况讨论即可