#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/90671583
using namespace std;
struct Apple {
  int weight;
  int length;
} arr[5010];
bool fun(Apple a, Apple b) { return a.weight < b.weight; }
int n, s, a, b, cnt;
int main() {
  cin >> n >> s;
  cin >> a >> b;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].length >> arr[i].weight;
  }
  int power = s;
  sort(arr + 1, arr + 1 + n, fun);
  for (int i = 1; i <= n; i++) {
    if (arr[i].length <= a + b) {
      if (arr[i].weight <= power && power != 0) {
        power = power - arr[i].weight;
        cnt++;
      }
    }
  }
  cout << cnt;
  return 0;
}