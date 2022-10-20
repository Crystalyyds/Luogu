#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/90348401
struct coin {
  int m;
  int w;
} arr[110];
bool fun(coin a, coin b) { return a.w * b.m > b.w * a.m; }
int n, t, c, i;
int main() {
  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].m >> arr[i].w;
  }
  c = t;
  float ans = 0;
  sort(arr, arr + n, fun);
  cout << "====================" << endl;
  for (i = 0; i < n; i++) {
    cout << arr[i].m << " " << arr[i].w << endl;
  }
  for (i = 0; i < n; i++) {
    if (arr[i].m > c) break;
    c -= arr[i].m;
    ans += arr[i].w;
  }
  if (i < n) {
    ans += 1.0 * c / arr[i].m * arr[i].w;
  }
  printf("%.2f", ans);
  return 0;
}
