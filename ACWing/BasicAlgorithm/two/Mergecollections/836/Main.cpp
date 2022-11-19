#include <bits/stdc++.h>
using namespace std;
//    https://www.acwing.com/solution/content/33345/
//    https://www.acwing.com/solution/content/20690/
//    https://blog.csdn.net/weixin_44536804/article/details/123395115
int n, m;
int p[100010];
int find(int x) {
  if (p[x] != x) {
    p[x] = find(p[x]);
  }
  return p[x];
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
  }
  while (m--) {
    char tt[2];
    int a, b;
    scanf("%s%d%d", tt, &a, &b);
    if (tt[0] == 'M') {
      p[find(a)] = find(b);
    } else {
      if (find(a) == find(b)) {
        cout << "Yes" << endl;
      } else {
        cout << "No" << endl;
      }
    }
  }
  return 0;
}
