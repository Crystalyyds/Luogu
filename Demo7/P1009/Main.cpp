#include <bits/stdc++.h>
using namespace std;
int n, temp = 1, cnt;
int main() {
  cin >> n;
  int a = 1;
  while (a <= n) {
    temp = temp * a;
    cnt += temp;
    a++;
  }
  cout << cnt << endl;
}