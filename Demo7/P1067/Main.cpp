
#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/88713514
using namespace std;
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
