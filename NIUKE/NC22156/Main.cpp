#include <bits/stdc++.h>
using namespace std;
// https://ac.nowcoder.com/acm/problem/22156
int n, cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      cnt -= i;
    } else {
      cnt += i;
    }
  }
  cout << cnt << endl;
}