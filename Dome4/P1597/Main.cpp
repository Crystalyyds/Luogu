#include <bits/stdc++.h>

#include <map>
using namespace std;
// https://www.luogu.com.cn/record/87824873
string a;
int num = 0;
int main() {
  map<char, char> map;
  cin >> a;
  char temp;
  int index = a.find('=');
  while (index != -1) {
    temp = '0';
    if (a[index + 1] >= '0' && a[index + 1] <= '9') {
      map[a[num]] = a[index + 1];
    } else if ((a[index + 1] >= 'A' && a[index + 1] <= 'Z') ||
               (a[index + 1] >= 'a' && a[index + 1] <= 'z')) {
      if (map.find(a[index + 1]) != map.end()) {
        map[a[num]] = map[a[index + 1]];
      } else {
        map[a[num]] = '0';
      }
    } else {
      map[a[num]] = '0';
    }

    num += 5;
    index = a.find('=', index + 2);
  }
  for (auto it : map) {
    cout << it.second << " ";
  }
  return 0;
}