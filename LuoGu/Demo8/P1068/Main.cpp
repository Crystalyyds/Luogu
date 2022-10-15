#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/89916045
int n, m;
int ww, tot, l;
struct people {
  int index;
  int nums;
} arr[5010];
bool fun(people a, people b) {
  if (a.nums != b.nums) {
    return a.nums > b.nums;
  } else {
    return a.index < b.index;
  }
}

int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].index >> arr[i].nums;
  }
  ww = m * 1.5;
  sort(arr + 1, arr + 1 + n, fun);
  tot = arr[ww].nums;
  for (int i = 1; i <= n; i++) {
    if (arr[i].nums >= tot) {
      l++;
    }
  }
  cout << tot << " " << l << endl;
  for (int i = 1; i <= l; i++) {
    cout << arr[i].index << " " << arr[i].nums << endl;
  }
  return 0;
}