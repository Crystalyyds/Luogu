#include <bits/stdc++.h>
using namespace std;
long long n, x, arr[100010], cnt;
// https://www.luogu.com.cn/record/90551603
int main() {
  cin >> n >> x;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++) {
    if (arr[i] + arr[i + 1] <= x) {
      continue;
    } else {
      cnt += arr[i] + arr[i + 1] - x;
      if (x - arr[i] < 0) {
        arr[i + 1] = 0;
        arr[i] = arr[i] - abs(x - arr[i]);
      } else {
        arr[i + 1] = x - arr[i];
      }
    }
  }
  cout << cnt << endl;
  return 0;
}