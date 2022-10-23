#include <bits/stdc++.h>
using namespace std;
long long n, g, arr[30010], cnt;
// https://www.luogu.com.cn/record/90806217
int main() {
  cin >> g;
  cin >> n;
  for (long long i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + n + 1);
  long long j = 1;
  for (int i = n; i >= j; i--) {
    if (arr[j] + arr[i] > g) {
      cnt++;
    } else {
      j++;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}