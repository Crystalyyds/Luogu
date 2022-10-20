#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/90515506
int n, cnt, temp;
struct rate {
  int begin;
  int end;
} arr[1000010];
bool fun(rate a, rate b) { return a.end < b.end; }
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].begin >> arr[i].end;
  }
  sort(arr, arr + n, fun);
  for (int i = 0; i < n; i++) {
    if (temp <= arr[i].begin) {
      temp = arr[i].end;
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}