#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/88799833
#include <list>
using namespace std;
int m, n, cnt;
list<int> li;
int main() {
  cin >> m >> n;
  for (int i = 1; i <= n; i++) {
    int a = 0;
    cin >> a;
    list<int>::iterator it = find(li.begin(), li.end(), a);
    if (li.size() == 0) {
      li.push_back(a);
      cnt++;
    } else if (it != li.end()) {
      continue;
    } else if (it == li.end()) {
      if (li.size() < m) {
        li.push_back(a);
        cnt++;
      } else if (li.size() == m) {
        li.pop_front();
        li.push_back(a);
        cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}