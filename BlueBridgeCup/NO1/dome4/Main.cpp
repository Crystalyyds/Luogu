#include <bits/stdc++.h>
using namespace std;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt;
vector<string> ww;
int op = 30;
int main() {
  while (op--) {
    string aa;
    cin >> aa;
    ww.push_back(aa);
  }
  for (int i = 1; i <= 28; i++) {
    for (int j = 1; j <= 58; j++) {
      if ((ww.at(i)[j] - 'A') < (ww.at(i - 1)[j] - 'A') &&
          (ww.at(i)[j] - 'A') < (ww.at(i)[j + 1] - 'A') &&
          (ww.at(i)[j] - 'A') < (ww.at(i + 1)[j] - 'A') &&
          (ww.at(i)[j] - 'A') < (ww.at(i)[j - 1] - 'A')) {
        cnt++;
      }
    }
  }
  cout << cnt << endl;
}