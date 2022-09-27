#include <bits/stdc++.h>
using namespace std;
int n;
string str;
int main() {
  int cnt = 0, num = 0;
  cin >> n >> str;
  int first = (int)str.find('V');
  int end = (int)str.find('K');
  while (first != -1) {
    if (str[first] == 'V' && str[first + 1] == 'V') {
      first++;
    }
    if (str[first + 1] == 'K') {
      cnt++;
      first = str.find('V', first + 1);
    }
    if (str[first + 1] == 'V' && str[first + 2] != 'K' && num == 0) {
      str[first + 1] = 'K';
      cnt++;
      first = str.find('V', first + 1);
      num++;
    }
    if (str[end - 1] != 'V' && num == 0 && str[end + 1] == 'K') {
      str[end + 1] = 'V';
      cnt++;
      end = str.find('K', end + 1);
      num += 1;
    }
    if (first + 1 == str.length()) {
      break;
    }
  }
  cout << cnt << endl;
}