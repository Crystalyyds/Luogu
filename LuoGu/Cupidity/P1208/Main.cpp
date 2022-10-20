#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/90675832
struct milk {
  int value;
  int weight;
} arr[5010];
bool fun(milk a, milk b) { return a.value < b.value; }
int n, m, cnt;
int main() {
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> arr[i].value >> arr[i].weight;
  }
  sort(arr + 1, arr + 1 + m, fun);
  for (int i = 1; i <= m; i++) {
    if (arr[i].weight <= n) {
      cnt += arr[i].weight * arr[i].value;
      n -= arr[i].weight;
    } else {
      cnt += arr[i].value * n;
      break;
    }
  }
  cout << cnt;
  return 0;
}