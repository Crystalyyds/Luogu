#include <bits/stdc++.h>
using namespace std;
int n, g, arr[30010], cnt;
int main() {
  cin >> g;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  int j = 1;
  for (int i = n; i >= j; i--) {
    if (arr[j] + arr[i] > 100) {
      cnt++;
    } else {
      j++;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}