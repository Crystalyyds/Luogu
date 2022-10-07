#include <bits/stdc++.h>

using namespace std;
int n, m, op, a, b;
int num = 0;

int main() {
  vector<int> li;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    li.push_back(temp);
  }
  cin >> m;
  while (m--) {
    cin >> op;
    switch (op) {
      case 1:
        cin >> a >> b;
        auto it = li.begin();
        while (a) {
          it++;
        }
        li.insert(it, b);
        for (it = li.begin(); it != li.end(); it++) {
          cout << *it << " ";
        }
        cout << endl;
        break;
      case 2:
        cin >> a;
        it = li.begin();
        while (a) {
          it++;
        }
        li.erase(it);
        for (it = li.begin(); it != li.end(); it++) {
          cout << *it << " ";
        }
        cout << endl;
        break;
      case 3:
        cin >> a >> b;
        it = li.begin();
        while (a) {
          it++;
        }
        li.insert(it, b);
        for (it = li.begin(); it != li.end(); it++) {
          if (num != a + 1) {
            cout << *it << " ";
          } else {
          }
          num++;
        }
        cout << endl;
        break;
      case 4:
        cin >> a;
        it = li.begin();
        while (a) {
          it++;
        }
        it = it;
        cout << *it << endl;
        cout << endl;
        break;
      default:
        break;
    }
  }
}