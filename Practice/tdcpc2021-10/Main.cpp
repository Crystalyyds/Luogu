#include <bits/stdc++.h>

#include <list>
using namespace std;
int n, m, op, a, b;
int num = 0;

int main() {
  list<int>::iterator it;
  list<int> list;
  it = begin(list);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int temp;
    cin >> temp;
    list.push_back(temp);
  }
  cin >> m;
  while (m--) {
    cin >> op;
    switch (op) {
      case 1:
        cin >> a >> b;
        it = list.begin();
        while (a) {
          it++;
        }
        list.insert(it, b);
        for (it = list.begin(); it != list.end(); it++) {
          cout << *it << " ";
        }
        cout << endl;
        break;
      case 2:
        cin >> a;
        it = list.begin();
        while (a) {
          it++;
        }
        list.erase(it);
        for (it = list.begin(); it != list.end(); it++) {
          cout << *it << " ";
        }
        cout << endl;
        break;
      case 3:
        cin >> a >> b;
        it = list.begin();
        while (a) {
          it++;
        }
        list.insert(it, b);
        for (it = list.begin(); it != list.end(); it++) {
          if (num != a + 1) {
            cout << *it << " ";
          } else {
            list.remove(*it);
          }
          num++;
        }
        cout << endl;
        break;
      case 4:
        cin >> a;
        it = list.begin();
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