#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;

int n, m;
int path[N][N];   //存储地图
int judge[N][N];  //存储距离

void fun(int a, int b) {
  queue<PII> arr;
  arr.push({a, b});

  memset(judge, -1, sizeof judge);  //初始化各个点到源点的距离为-1
  path[1][1] = 0;                   //源点到自己的距离为0
  int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  while (!arr.empty()) {
    auto start = arr.front();
    arr.pop();  //弹出
    for (int i = 0; i < 4; i++) {
      int x = start.first + dx[i];
      int y = start.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && path[x][y] == 0 &&
          judge[x][y] == -1) {
        // judge[x][y] == -1表示没有呗访问
        judge[x][y] = judge[start.first][start.second] + 1;
        arr.push({x, y});
      }
    }
  }
  cout << judge[n][m];
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> path[i][j];
    }
  }
  fun(1, 1);
  return 0;
}