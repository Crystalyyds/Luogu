#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87738216
string s;
int b, g;

int main() {
  cin >> s;
  int n = s.size();
  for (int i = 0; i < n; i++) {
    if (s[i] == 'b') b++;
    if (s[i] == 'o' && s[i - 1] != 'b') b++;
    if (s[i] == 'y' && s[i - 1] != 'o' && s[i - 2] != 'b') b++;
    if (s[i] == 'g') g++;
    if (s[i] == 'i' && s[i - 1] != 'g') g++;
    if (s[i] == 'r' && s[i - 1] != 'i' && s[i - 2] != 'g') g++;
    if (s[i] == 'l' && s[i - 1] != 'r' && s[i - 2] != 'i' && s[i - 3] != 'g')
      g++;
  }
  cout << b << endl << g << endl;
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// int cntb, cntg, a[3], b[4];
// int fun(string sc, string str) {
//   int ob = str.find(sc);
//   int count = 0;
//   while (ob != -1) {
//     count++;
//     ob = str.find(sc, ob + sc.length());
//   }
//   return count;
// }
// string str;
// int main() {
//   cin >> str;
//   string a1[3] = {"boy", "o", "y"};
//   string b1[4] = {"girl", "i", "r", "l"};
//   for (int i = 0; i < 3; i++) {
//     a[i] = fun(a1[i], str);
//   }
//   for (int i = 0; i < 4; i++) {
//     b[i] = fun(b1[i], str);
//   }
//   cntb += a[0];
//   for (int i = 1; i < 3; i++) {
//     if (a[i] != a[0]) {
//       cntb += a[i] - a[0];
//     } else {
//       continue;
//     }
//   }
//   cntg += b[0];
//   for (int i = 1; i < 4; i++) {
//     if (b[i] != b[0]) {
//       cntb += a[i] - a[0];
//     } else {
//       continue;
//     }
//   }
//   cout << cntb << endl;
//   cout << cntg << endl;
// }