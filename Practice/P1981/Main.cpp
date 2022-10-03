#include <bits/stdc++.h>

#include <stack>
using namespace std;
stack<int> x;
string str, a;
int m = 10000, cnt;
int main() {
  cin >> str;
  for (int i = 0; i < str.size(); i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      a += str[i];
    } else if (str[i] == '*') {
      if (str.find(i + 1, '+') != -1) {
        string temp = str.substr(i + 1, str.find(i + 1, '+'));
        int inta = atoi(a.c_str());
        int intb = atoi(temp.c_str());
        cnt = (inta * intb) % m;
        x.push(cnt % m);
      } else {
        int intb = atoi(str.substr(i + 1, str.size() - 1).c_str());
        x.push(intb % m);
      }

    } else {
      if (str.find(i + 1, '*') != -1) {
        string temp = str.substr(i + 1, str.find(i + 1, '*'));
        int intb = atoi(temp.c_str());
        x.push(intb % m);
      } else {
        int intb = atoi(str.substr(i + 1, str.size() - 1).c_str());
        x.push(intb % m);
      }
    }
  }
  int num = 0;
  while (x.size()) {
    num += x.top();
    num %= m;
    x.pop();
  }
  cout << num << endl;
}
