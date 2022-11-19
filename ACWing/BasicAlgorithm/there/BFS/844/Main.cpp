#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 110;

int n, m;
int path[N][N];   //�洢��ͼ
int judge[N][N];  //�洢����

void fun(int a, int b) {
  queue<PII> arr;
  arr.push({a, b});

  memset(judge, -1, sizeof judge);  //��ʼ�������㵽Դ��ľ���Ϊ-1
  path[1][1] = 0;                   //Դ�㵽�Լ��ľ���Ϊ0
  int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
  while (!arr.empty()) {
    auto start = arr.front();
    arr.pop();  //����
    for (int i = 0; i < 4; i++) {
      int x = start.first + dx[i];
      int y = start.second + dy[i];
      if (x >= 1 && x <= n && y >= 1 && y <= m && path[x][y] == 0 &&
          judge[x][y] == -1) {
        // judge[x][y] == -1��ʾû���·���
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