#include <bits/stdc++.h>
using namespace std;
int fun(int a, int b) {
  if (a == 1 || b == 1) return true;
  while (1) {
    int t = a % b;
    if (t == 0) {
      break;
    } else {
      a = b;
      b = t;
    }
  }
  if (b > 1)
    return 0;
  else
    return 1;
}
int n, cnt, arr[6010];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (fun(arr[i], arr[j]) == 1) {
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}