#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
// https://www.luogu.com.cn/record/93814681
const int N = 410;
int n, m, x, y, arr[N][N], brr[N][N];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1}, dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
void fun() {
  queue<PII> queue;
  queue.push({x, y});
  while (!queue.empty()) {
    PII temp = queue.front();
    queue.pop();
    for (int i = 0; i < 8; i++) {
      int x = temp.first + dx[i];
      int y = temp.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && brr[x][y] == 0) {
        brr[x][y] = 1;
        arr[x][y] = arr[temp.first][temp.second] + 1;
        queue.push({x, y});
      }
    }
  }
}
int main() {
  cin >> n >> m >> x >> y;
  memset(arr, -1, sizeof(arr));
  arr[x][y] = 0;
  brr[x][y] = 1;
  fun();
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}