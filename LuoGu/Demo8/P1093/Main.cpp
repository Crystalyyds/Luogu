#include <bits/stdc++.h>
using namespace std;
struct one {
  int i;
  int yw;
  int sx;
  int yy;
} arr[310];
bool fun(one a, one b) {
  if (a.sx + a.yw + a.yy != b.sx + b.yw + b.yy) {
    return a.sx + a.yw + a.yy > b.sx + b.yw + b.yy;
  } else {
    return a.yw > b.yw;
  }
}
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].yw >> arr[i].sx >> arr[i].yy;
    arr[i].i = i;
  }
  sort(arr + 1, arr + n + 1, fun);
  for (int i = 1; i <= 5; i++) {
    cout << arr[i].i << " " << arr[i].yw + arr[i].sx + arr[i].yy << endl;
  }
  return 0;
}