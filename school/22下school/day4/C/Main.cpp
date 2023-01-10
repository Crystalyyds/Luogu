#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  vector<int> ll;
  cin >> n;
  for (int i = 0; i < n; i++) {
    char op;
    int temp;
    cin >> op >> temp;
    if (ll.size() == 0) {
      ll.push_back(temp);
    } else if (op == 'L') {
      ll.insert(ll.begin(), temp);
    } else if (op == 'R') {
      ll.push_back(temp);
    } else if (op == '?') {
      vector<int>::iterator result = find(ll.begin(), ll.end(), temp);
      if (result != ll.end()) {
        int ad = (&*result - &ll[0]) + 1;
        if (ll.size() == 1) {
          cout << 1 << endl;
        } else {
          if (ll.size() - ad < ad - 1) {
            cout << ll.size() - ad << endl;
          } else {
            cout << ad - 1 << endl;
          }
        }
      }
    }
  }
}