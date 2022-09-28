#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87778523
string a, b;
int a1 = 1, b1 = 1;
int main() {
  cin >> a >> b;
  for (int i = 0; i < a.length(); i++) {
    a1 *= a[i] - 'A' + 1;
  }
  for (int i = 0; i < b.length(); i++) {
    b1 *= b[i] - 'A' + 1;
  }
  if ((a1 % 47) == (b1 % 47)) {
    cout << "GO" << endl;
  } else {
    cout << "STAY" << endl;
  }
  return 0;
}