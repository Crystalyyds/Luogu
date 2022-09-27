#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87658437
int main() {
  string a, b;
  // getline ÊäÈë°üÀ¨¿Õ¸ñ
  getline(cin, a);
  getline(cin, b);
  for (int i = 0; i < a.length(); i++) {
    if (a[i] <= 'Z' && a[i] >= 'A') {
      a[i] = a[i] + 32;
    }
  }
  for (int i = 0; i < b.length(); i++) {
    if (b[i] <= 'Z' && b[i] >= 'A') {
      b[i] = b[i] + 32;
    }
  }
  a = ' ' + a + ' ';
  b = ' ' + b + ' ';
  int first = b.find(a);
  int count = 0;
  if (first == -1) {
    cout << -1;
  } else {
    int next = b.find(a);
    while (next != -1) {
      count++;
      next = b.find(a, next + 1);
    }
    cout << count << " " << first << endl;
  }
}