#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/88187273
int n, e, cnt;
char k;
char arr[1000000 * 6 + 10];
int main() {
  int w = 0;
  cin >> n >> e;
  k = '2';
  for (int i = n; i <= e; i++) {
    std::string s = std::to_string(i);
    for (int j = 0; j < s.length(); j++) {
      arr[w++] = s[j];
    }
  }
  for (int i = 0; i < w; i++) {
    if (arr[i] == k) {
      cnt++;
    }
  }
  cout << cnt << endl;
  return 0;
}