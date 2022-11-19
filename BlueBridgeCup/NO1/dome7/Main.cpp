#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  char temp;
  cin >> s;
  for (int i = 0; i <= s.size() - 1; i++) {
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' ||
        s[i] == 'u') {
      temp = s[i] - 32;
      s[i] = temp;
    }
  }
  for (int i = 0; i <= s.size() - 1; i++) {
    cout << s[i];
  }
  return 0;
}