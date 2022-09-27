#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87638440
int n, m, arr[3010], mi, cnt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= m; i++) {
    mi += arr[i];
  }
  for (int i = 1; i <= n - m + 1; i++) {
    cnt = 0;
    for (int j = i; j <= i + m - 1; j++) {
      cnt += arr[j];
    }
    if (cnt < mi) {
      mi = cnt;
    }
  }
  cout << mi << endl;
}