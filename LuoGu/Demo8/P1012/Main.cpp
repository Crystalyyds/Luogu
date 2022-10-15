#include <bits/stdc++.h>
using namespace std;
int n;
bool fun(string a, string b) {
  if (a[0] != b[0]) {
    return a[0] > b[0];
  } else {
  }
}
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