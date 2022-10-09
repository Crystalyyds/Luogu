#include <bits/stdc++.h>
using namespace std;
long long n, arr[2 * 100000 + 10];
int main() {
  cin >> n;
  int nn = 0;
  for (int i = 1; i <= n; i++) {
    if (i <= 2) {
      cin >> arr[i];
    } else {
      cin >> arr[i];
      int a = max(arr[i], arr[i - 1]);
    }
  }
  int max = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cnt = 0;
      if (i != j) {
        cnt += arr[i] + arr[j];
        if (cnt % 2 == 0) {
          if (cnt > max) {
            max = cnt;
            nn = 1;
          }
        }
      }
    }
  }
  if (nn == 1) {
    cout << max << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}