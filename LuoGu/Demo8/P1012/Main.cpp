#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/89995497
int n;
bool fun(string a, string b) { return a + b > b + a; }
string arr[30];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n, fun);
  for (int i = 0; i < n; i++) {
    cout << arr[i];
  }
  return 0;
}