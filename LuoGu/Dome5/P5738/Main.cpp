#include <bits/stdc++.h>

using namespace std;
// https://www.luogu.com.cn/record/87897143
int main() {
  int n, m;
  cin >> n >> m;
  float res = -1;
  while (n--) {
    float t = 0, Min = 100, Max = 0;
    float ans = 0;
    for (int i = 0; i < m; i++) {
      cin >> t;
      ans += t;
      Min = min(t, Min), Max = max(t, Max);
    }

    ans -= Min + Max;

    ans /= m - 2.0;

    res = max(ans, res);
  }

  printf("%.2f", res);
  return 0;
}