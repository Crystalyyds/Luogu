#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  double cnt = 0;
  for (n = 0; cnt <= 12;) {
    n++;
    cnt = cnt + (1.0 / n);
  }
  cout << n << endl;
}