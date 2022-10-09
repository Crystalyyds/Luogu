#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/89115283
string str;
int main() {
  stack<int> sa;
  cin >> str;
  long long size = str.length();
  long long ww = 0;
  for (int i = 0; i < size; i++) {
    char temp = str[i];
    if (temp == '.') {
      sa.push(ww);
      ww = 0;
      continue;
    } else if (temp == '+') {
      int a = sa.top();
      sa.pop();
      int b = sa.top();
      sa.pop();
      sa.push(a + b);
    } else if (temp == '-') {
      int a = sa.top();
      sa.pop();
      int b = sa.top();
      sa.pop();
      sa.push(b - a);
    } else if (temp == '*') {
      int a = sa.top();
      sa.pop();
      int b = sa.top();
      sa.pop();
      sa.push(a * b);
    } else if (temp == '/') {
      int a = sa.top();
      sa.pop();
      int b = sa.top();
      sa.pop();
      sa.push(b / a);
    } else if (temp == '@') {
      break;
    } else {
      ww = ww * 10 + (int)temp - '0';
    }
  }
  int cnt = sa.top();
  sa.pop();
  cout << cnt << endl;
  return 0;
}