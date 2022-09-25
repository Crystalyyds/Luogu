#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int w;
    cin >> w;
    string a, b;
    cin >> a >> b;
    int count = 0;
    for (int i = 0; i < w; i++) {
      if ((a[i] == 'G' && b[i] == 'B') || (b[i] == 'G' && a[i] == 'B')) {
        count++;
      }
      if (a[i] == b[i]) {
        count++;
      }
    }
    if (count == w) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}