#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87233946
int main() {
  long long m, n;
  int array[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int i, j;
  cin >> m >> n;
  for (i = m; i <= n; i++) {
    j = i;
    while (j > 0) {
      if (j % 10 == 0) array[0] += 1;
      if (j % 10 == 1) array[1] += 1;
      if (j % 10 == 2) array[2] += 1;
      if (j % 10 == 3) array[3] += 1;
      if (j % 10 == 4) array[4] += 1;
      if (j % 10 == 5) array[5] += 1;
      if (j % 10 == 6) array[6] += 1;
      if (j % 10 == 7) array[7] += 1;
      if (j % 10 == 8) array[8] += 1;
      if (j % 10 == 9) array[9] += 1;
      j = j / 10;
    }
  }
  for (int i = 0; i < 10; i++) {
    cout << array[i] << " ";
  }
  return 0;
}
