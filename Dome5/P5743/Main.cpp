#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87992641
int n;
int main() {
  cin >> n;
  int cnt = 1;
  for (int i = 1; i <= n - 1; i++) {
    cnt = (cnt + 1) * 2;
  }
  cout << cnt << endl;
}
