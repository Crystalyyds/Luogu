#include <bits/stdc++.h>
using namespace std;
int n, arr[10];
bool brr[10];
void fun(int u) {
  if (u > n) {
    for (int i = 1; i <= n; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    if (!brr[i]) {
      arr[u] = i;
      brr[i] = true;
      fun(u + 1);
      brr[i] = false;
    }
  }
}
int main() {
  cin >> n;
  fun(1);
  return 0;
}