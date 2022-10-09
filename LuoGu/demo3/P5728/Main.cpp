#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87264979

int main() {
  int n, array[1010][5], sum[1010];
  int M = 0;

  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> array[i][1] >> array[i][2] >> array[i][3];
    sum[i] = array[i][1] + array[i][2] + array[i][3];
  }
  for (int i = 1; i <= n; i++)
    for (int j = i + 1; j <= n; j++)
      if (abs(array[i][1] - array[j][1]) <= 5 &&
          abs(array[i][2] - array[j][2]) <= 5 &&
          abs(array[i][3] - array[j][3]) <= 5 && abs(sum[i] - sum[j]) <= 10)
        M++;
  cout << M << endl;
  return 0;
}