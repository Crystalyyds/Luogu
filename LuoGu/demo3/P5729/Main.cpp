#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87411940
int main() {
  int w, x, h;
  int array[30][30][30];

  cin >> w >> x >> h;
  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= x; j++) {
      for (int k = 1; k <= h; k++) {
        array[i][j][k] = 1;
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int x1, y1, z1, x2, y2, z2;
    cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
    for (int i = min(x1, x2); i <= max(x1, x2); i++) {
      for (int j = min(y1, y2); j <= max(y1, y2); j++) {
        for (int k = min(z1, z2); k <= max(z1, z2); k++) {
          array[i][j][k] = 0;
        }
      }
    }
  }
  int count = 0;
  for (int i = 1; i <= w; i++) {
    for (int j = 1; j <= x; j++) {
      for (int k = 1; k <= h; k++) {
        if (array[i][j][k] == 1) {
          count++;
        }
      }
    }
  }
  cout << count << endl;
}
