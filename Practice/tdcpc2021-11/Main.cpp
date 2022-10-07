#include <bits/stdc++.h>
using namespace std;
int x, y;
int main() {
  cin >> x >> y;
  for (int i = x; i <= y; i++) {
    if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0) {
      cout << i << " ";
    }
  }
  return 0;
}