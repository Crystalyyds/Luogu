#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/88924512
int arr[10010];
int m, cnt;
int main() {
  for (int j = 0; j < 10; j++) {
    cin >> arr[j];
  }
  cin >> m;
  m = m + 30;
  for (int j = 0; j < 10; j++) {
    if (m >= arr[j]) {
      cnt++;
    }
  }
  cout << cnt << endl;
}