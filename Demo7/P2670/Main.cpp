#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/88593085
char arr[105][105];
int a[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int b[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int main() {
  int m, n;
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> arr[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      int cnt = 0;
      if (arr[i][j] == '*') {
        for (int w = 0; w < 8; w++) {
          if (arr[i + a[w]][j + b[w]] != '*') {
            arr[i + a[w]][j + b[w]] += 1;
          }
        }
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    for (int j = 1; j <= n; j++) {
      if (arr[i][j] != '*') {
        cout << (char)(arr[i][j] - 15);
      } else {
        cout << arr[i][j];
      }
    }
    cout << endl;
  }
}
