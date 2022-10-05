#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/88715585
#include <set>
using namespace std;
int m;
set<int> s;
int main() {
  set<int>::iterator it;
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int temp;
    cin >> temp;
    s.insert(temp);
  }
  cout << s.size() << endl;
  for (it = s.begin(); it != s.end(); it++) {
    cout << *it << " ";
  }
}