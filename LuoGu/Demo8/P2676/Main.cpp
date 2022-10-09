#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/89286080
long long n, b, arr[20010], cnt;
int main() {
  cin >> n >> b;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 2; i <= n; i++) {
    int temp = arr[i], j;
    for (j = i - 1; j >= 1; j--) {
      if (arr[j] < temp) {
        arr[j + 1] = arr[j];
      } else {
        break;
      }
      arr[j] = temp;
    }
  }
  for (int i = 1; i <= n; i++) {
    cnt += arr[i];
    if (cnt >= b) {
      cout << i << endl;
      break;
    }
  }
}