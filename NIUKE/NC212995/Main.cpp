#include <bits/stdc++.h>
using namespace std;
// https://ac.nowcoder.com/acm/problem/212995
int n, a, b, mx = 100, mn = 0;
int main() {
  cin >> n >> a >> b;
  if (a > b) {
    mx = b;
  } else {
    mx = a;
  }
  int tempmin = min(a, b);
  if (a + b > n) {
    mn = a + b - n;
  }
  if (mn > tempmin) {
    mn = tempmin;
  }
  cout << mx << " " << mn << endl;
  return 0;
}