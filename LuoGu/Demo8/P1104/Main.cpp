#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/89699746
int n;
struct people {
  string name;
  int index;
  int y;
  int m;
  int d;
} arr[110];
bool fun(people a, people b) {
  if (a.y != b.y) {
    return a.y < b.y;
  } else {
    if (a.m != b.m) {
      return a.m < b.m;
    } else {
      if (a.d != b.d) {
        return a.d < b.d;
      } else {
        return a.index > b.index;
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].name >> arr[i].y >> arr[i].m >> arr[i].d;
    arr[i].index = i + 1;
  }
  sort(arr, arr + n, fun);
  for (int i = 0; i < n; i++) {
    cout << arr[i].name << endl;
  }
  return 0;
}