#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87655888
int m, l, r, op;
string s, a;
int main() {
  cin >> m;
  cin >> a;
  while (m--) {
    cin >> op;
    if (op == 1) {
      cin >> s;
      a.append(s);
      cout << a << endl;
    }
    if (op == 2) {
      cin >> l >> r;
      a = a.substr(l, r);
      //½ØÈ¡l µ½ r
      cout << a << endl;
    }
    if (op == 3) {
      cin >> l >> s;
      a.insert(l, s);
      cout << a << endl;
    }
    if (op == 4) {
      cin >> s;
      cout << (int)a.find(s) << endl;
    }
  }
  return 0;
}
