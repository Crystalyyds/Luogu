#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87891415
int arr[1500 / 4 + 10];
int main() {
  int a, b, s = 0;
  cin >> a >> b;
  for (int i = a; i <= b; i++)
    if (i % 400 == 0 || i % 4 == 0 && i % 100) {
      arr[s++] = i;
    }
  cout << s << endl;
  for (int i = 0; i < s; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}