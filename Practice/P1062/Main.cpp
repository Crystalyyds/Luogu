#include <bits/stdc++.h>
using namespace std;
int k, n, cnt, arr[1010];
int main() {
  int w = 0;
  cin >> k >> n;
  for (int i = 0; i < n; i++) {
    arr[w++] = pow(k, i);
    int j = i;
    while (j--) {
      arr[w++] = pow(k, i) + pow(k, j);
    }
  }
}