#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/87944486
using namespace std;
int fun(int n) {
  if (n == 1) {
    return 1;
  } else {
    return n * fun(n - 1);
  }
}
int main() {
  int n;
  cin >> n;
  cout << fun(n) << endl;
}