#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/93840183
int n, m, arr[1000010];
int main() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while (m--) {
    int temp;
    cin >> temp;
    int l = 0, r = n - 1;
    while (l < r) {
      int mid = l + r >> 1;
      if (arr[mid] >= temp) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    if (arr[l] == temp)
      cout << l + 1 << " ";
    else
      cout << "-1 ";
  }

  return 0;
}