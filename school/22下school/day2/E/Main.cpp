#include <bits/stdc++.h>

#include <set>
using namespace std;

int fun(int na, int n1, int n2) {
  if (n2 = n1 + na) {
    return 3;
  }
  if (n2 < na + n1) {
    return 1;
  }
  if (n2 == na) {
    return 0;
  }
  return 0;
}
int main() {
  int n, w;
  cin >> n >> w;
  for (int j = 0; j < w; j++) {
    int na = 0, nb1 = 0, nb2 = 0, nc1 = 0, nc2 = 0, arr1[3], arr2[3], arr3[3],
        count1 = 0, count2 = 0, count3 = 0;
    set<char> sa, sb, sc;
    for (int i = 0; i < n; i++) {
      string a, b, c;
      cin >> a >> b >> c;
      for (int i = 0; i < a.size(); i++) {
        sa.insert(a[i]);
      }
      arr1[0] = sa.size();
      for (int i = 0; i < b.size(); i++) {
        sb.insert(b[i]);
      }
      arr2[0] = sb.size();

      for (int i = 0; i < b.size(); i++) {
        sc.insert(c[i]);
      }
      arr3[0] = sc.size();

      for (set<char>::iterator i = sb.begin(); i != sb.end(); i++) {
        sa.insert(*i);
      }

      arr1[1] = sa.size();

      for (set<char>::iterator i = sc.begin(); i != sc.end(); i++) {
        sa.insert(*i);
      }
      arr1[2] = sa.size();

      for (set<char>::iterator i = sa.begin(); i != sa.end(); i++) {
        sb.insert(*i);
      }
      arr2[1] = sb.size();

      for (set<char>::iterator i = sc.begin(); i != sc.end(); i++) {
        sb.insert(*i);
      }
      arr2[2] = sb.size();

      for (set<char>::iterator i = sa.begin(); i != sa.end(); i++) {
        sc.insert(*i);
      }
      arr3[1] = sc.size();

      for (set<char>::iterator i = sb.begin(); i != sb.end(); i++) {
        sc.insert(*i);
      }
      arr3[2] = sc.size();
      count1 += fun(arr1[0], arr2[0], arr1[1]);
      count1 += fun(arr1[0], arr3[0], arr1[2]);

      count2 += fun(arr2[0], arr1[0], arr2[1]);
      count2 += fun(arr2[0], arr3[0], arr2[2]);

      count3 += fun(arr3[0], arr1[0], arr3[1]);
      count3 += fun(arr3[0], arr2[0], arr3[2]);

      cout << count1 << " " << count2 << " " << count3 << " " << endl;
    }
  }
}
