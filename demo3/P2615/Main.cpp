#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87582495
int main() {
  int n, k;
  scanf("%d", &n);
  int array[100][100], i = 1, j = n / 2 + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      array[i][j] = 0;
    }
  }
  array[1][n / 2 + 1] = 1;
  for (k = 2; k <= n * n; k++) {
    if ((i == 1) && (j != n)) {
      array[n][j + 1] = k;
      i = n;
      j++;
      continue;
    }
    if ((j == n) && (i != 1)) {
      array[i - 1][1] = k;
      i--;
      j = 1;
      continue;
    }
    if ((i == 1) && (j == n)) {
      array[i + 1][j] = k;
      i++;
      continue;
    }
    if ((i != 1) && (j != n)) {
      if (array[i - 1][j + 1] == 0) {
        array[i - 1][j + 1] = k;
        i--;
        j++;
      } else {
        array[i + 1][j] = k;
        i++;
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cout << array[i][j] << " ";
    }
    cout << endl;
  }
}