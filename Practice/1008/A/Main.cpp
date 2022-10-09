#include <bits/stdc++.h>
using namespace std;
int n, cnt;
int main() {
  cin >> n;
  while (n--) {
    int temp;
    cin >> temp;
    cnt += temp;
  }
  cout << cnt;
  return 0;
}