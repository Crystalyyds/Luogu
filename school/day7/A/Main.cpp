#include <bits/stdc++.h>
using namespace std;
long long n;
int cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
      continue;
    } else {
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}