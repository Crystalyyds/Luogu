#include <bits/stdc++.h>
using namespace std;
// https://ac.nowcoder.com/acm/problem/22240
int n, a, b, location;
int main() {
  cin >> n >> a >> b;
  for (int i = 1; i <= n; i++) {
    if (i > a && n - i <= b) {
      location++;
    }
  }

  cout << location << endl;
}