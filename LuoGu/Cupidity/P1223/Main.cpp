#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/90512465
using namespace std;
struct Time {
  int time;
  int index;
} arr[1010];
int n;
double cnt;
bool fun(Time a, Time b) {
  if (a.time != b.time) {
    return a.time < b.time;
  } else {
    return a.index < b.index;
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].time;
    arr[i].index = i + 1;
  }
  sort(arr, arr + n, fun);
  // cnt = arr[0].time;
  for (int i = 0; i < n; i++) {
    cout << arr[i].index << " ";
    cnt += arr[i].time * (n - 1 - i);
  }
  cout << endl;
  printf("%.2lf", cnt / n);
  return 0;
}