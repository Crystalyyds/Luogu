#include <bits/stdc++.h>
using namespace std;
int m, n;
typedef pair<int, int> mp;
vector<mp> add, query;
vector<int> all;
// all  �������Ե�λ��
int a[300010], b[300010];
//��300000  ����Ϊ��ǰ������ǰ׺�͵����أ�������2*m����
int find(int x) {
  int l = 0;
  int r = all.size() - 1;

  while (l < r) {
    int mid = (l + r) / 2;
    if (all[mid] >= x) {
      r = mid;
    } else {
      l = mid + 1;
    }
  }
  return r + 1;
}
int main() {
  cin >> m >> n;
  while (m--) {
    int l, r;
    cin >> l >> r;
    add.push_back({l, r});
    all.push_back(l);
  }
  while (n--) {
    int l, r;
    cin >> l >> r;
    query.push_back({l, r});
    all.push_back(l);
    all.push_back(r);
  }
  sort(all.begin(), all.end());
  all.erase(unique(all.begin(), all.end()), all.end());
  for (auto temp : add) {
    int x = find(temp.first);
    a[x] += temp.second;
  }
  for (int i = 1; i <= all.size(); i++) {
    b[i] = b[i - 1] + a[i];
    //ǰ׺�ͣ�i=1,����Խ�硣
  }
  for (auto temp : query) {
    int l = find(temp.first);
    int r = find(temp.second);
    cout << b[r] - b[l - 1] << endl;
  }
  return 0;
}