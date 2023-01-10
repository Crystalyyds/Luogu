#include <bits/stdc++.h>
using namespace std;
int m, n, arr[2000010];
int main() {
  scanf("%d", &n);
  scanf("%d", &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  int min = 0, index = 0;
  for (int i = 0, j = 0; i < n; i++) {
    if (i == 0) {
      cout << 0 << endl;
      continue;
    }
    if (i == 1) {
      min = arr[i];
      index = j;
    }
    if (index >= i - m) {
      while (i - j <= m) {
        if (arr[i] < min) {
          min = arr[i];
          index = j;
        }
        j++;
      }
    } else {
      min = arr[i];
      index = i - m;
      while (i - j <= m) {
        if (arr[i] < min) {
          min = arr[i];
          index = j;
        }
        j++;
      }
    }
    cout << index << endl;
  }
  return 0;
}