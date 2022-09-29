#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87890274
int arr[110], n;
int fun(int w) {
  if (w == 2) {
    return 1;
  }
  if (w > 2) {
    for (int i = 2; i <= sqrt(w); i++) {
      if (w % i == 0) {
        return 0;
      }
    }
    return 1;
  } else {
    return 0;
  }
}
int main() {
  cin >> n;
  int w = 0;
  while (n--) {
    cin >> arr[w];
    if (fun(arr[w]) == 1) {
      cout << arr[w] << " ";
    }
    w++;
  }
  return 0;
}
