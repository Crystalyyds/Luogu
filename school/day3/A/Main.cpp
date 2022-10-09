#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[50010], temp, ww;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> temp;
    ww += temp;
    arr[i] = ww;
  }
  cin >> m;
  while (m--) {
    long long cnt = 0;
    long long a = 0, b = 0;
    cin >> a >> b;
    if (a == 1) {
      cout << arr[b] << endl;
      ;
    } else {
      cnt = arr[a + b - 1] - arr[a - 1];
      cout << cnt << endl;
    }
  }
  return 0;
}