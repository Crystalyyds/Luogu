#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/87286104
using namespace std;
int main() {
  string s;
  int n, i, j;
  cin >> n;
  cin >> s;
  for (i = 0; i < s.size(); ++i) {
    for (j = 1; j <= n; ++j) {
      ++s[i];
      if (s[i] > 'z') s[i] = 'a';
    }
  }
  cout << s;
  return 0;
}