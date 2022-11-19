#include <bits/stdc++.h>
using namespace std;
vector<string> ww;
vector<int> a, b;
int n, u, i, arr[3], op, wp = 6, cnt, mp;
int main() {
  cin >> n;
  int pk = n;
  while (pk--) {
    string ad;
    cin >> ad >> u >> i;
    a.push_back(u);
    b.push_back(i);
    ww.push_back(ad);
  }
  for (int ak = 1; ak < n; ak++) {
    int bk = ak - 1;
    int xx1, xx2, yy1, yy2, zz1, zz2;
    int xxx1, xxx2, yyy1, yyy2, zzz1, zzz2;
    string z1, z2;
    wp = 6;
    for (int i = 0; i < 3; i++) {
      xx1 = (ww.at(ak)[wp] - '0') * 10 + (ww.at(ak)[wp + 1] - '0') * 1;
      xx2 = (ww.at(bk)[wp] - '0') * 10 + (ww.at(bk)[wp + 1] - '0') * 1;
      arr[op++] = xx1 - xx2;
      wp -= 3;
    }
    if (arr[2] <= 0) {
      if (arr[1] <= 0) {
        arr[0] -= 1;
        arr[1] = abs(arr[1]) - 1;
      } else {
        arr[1] -= 1;
      }
      arr[2] = abs(arr[2]);
    } else {
      if (arr[1] <= 0) {
        arr[0] -= 1;
        arr[1] = abs(arr[1]);
      }
    }
    cnt += ((arr[0] * 60 + arr[1]) * 60 + arr[0]) * a.at(mp++) * b.at(mp++);
  }
  cout << cnt;
  return 0;
}