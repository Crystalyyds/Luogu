// 803
#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
vector<pii> query, res;
int n;
int main() {
  cin >> n;
  while (n--) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
  }
  sort(query.begin(), query.end());
  //排序
  int st = -2e9, ed = -2e9;
  //初始边界
  for (auto temp : query) {
    if (temp.first > ed) {
      //开头不属于上一个区间
      if (ed != -2e9) {
        //排除第一个数。
        res.push_back({st, ed});
      }
      st = temp.first;
      ed = temp.second;

    } else if (temp.second > ed) {
      ed = temp.second;
    }
  }
  res.push_back({st, ed});
  cout << res.size();
  return 0;
}
