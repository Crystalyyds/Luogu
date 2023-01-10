#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
  scanf("%d", &n);
  while (n != 1) {
    if (n % 2 == 1) {
      n = n * 3 + 1;
      cnt++;
      continue;
    } else {
      n = n / 2;
      cnt++;
    }
  }
  cout << cnt;
  return 0;
}