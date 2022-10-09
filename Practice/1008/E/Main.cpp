#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[2 * 100000 + 10];
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  for (int i = 1; i <= m; i++) {
    int count = 0;
    for (int j = 1; j <= n; j++) {
      arr[j] += j;
      if (arr[j] <= 0) {
        count++;
      }
    }
    cout << count << endl;
  }
}