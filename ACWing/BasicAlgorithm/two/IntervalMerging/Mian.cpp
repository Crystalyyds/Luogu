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
  //����
  int st = -2e9, ed = -2e9;
  //��ʼ�߽�
  for (auto temp : query) {
    if (temp.first > ed) {
      //��ͷ��������һ������
      if (ed != -2e9) {
        //�ų���һ������
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
