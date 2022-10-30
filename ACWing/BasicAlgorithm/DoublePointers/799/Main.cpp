#include <bits/stdc++.h>
using namespace std;
int n, arr[100010], brr[100010], cnt;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  cnt = 0;
  for (int i = 1, j = 1; i <= n; i++) {
    brr[arr[i]] += 1;
    while (brr[arr[i]] > 1) {
      brr[arr[j]]--;
      j++;
    }
    cnt = max(cnt, i - j + 1);
  }
  cout << cnt << endl;
  return 0;
}