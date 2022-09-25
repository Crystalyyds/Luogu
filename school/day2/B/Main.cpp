#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long a, b, c;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a >> b >> c;
    int t1 = a;
    int t2 = abs(b - c) + c;
    if (t1 < t2) {
      cout << 1 << endl;
    }
    if (t1 == t2) {
      cout << 3 << endl;
    }
    if (t2 < t1) {
      cout << 2 << endl;
    }
  }
  return 0;
}