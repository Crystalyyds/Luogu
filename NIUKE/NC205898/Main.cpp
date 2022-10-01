#include <bits/stdc++.h>
using namespace std;
// https://ac.nowcoder.com/acm/problem/205898
int n;
int main() {
  cin >> n;
  if (n % 2 == 0) {
    cout << n / 2;
  } else {
    cout << n * 3 + 1;
  }
  return 0;
}