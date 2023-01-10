#include <bits/stdc++.h>
using namespace std;
string str;
int main() {
  getline(cin, str);
  int op = str.find(' ');
  int op1 = 0;
  while (op != -1) {
    for (int i = op - 1; i >= op1; i--) {
      cout << str[i];
    }
    cout << ' ';
    op1 = op + 1;
    op = str.find(' ', op1);
    if (op == -1) {
      for (int i = str.length() - 1; i >= op1; i--) {
        cout << str[i];
      }
      break;
    }
  }
  return 0;
}
//   while (cin >> str) {
//     for (int i = str.length() - 1; i >= 0; i--) {
//       cout << str[i];
//     }
//     cout << ' ';
//   }
