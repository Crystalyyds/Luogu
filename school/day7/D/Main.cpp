#include <bits/stdc++.h>
using namespace std;
int n, cnt, arr[500010], brr[500010];
vector<int> h;
void fun(int y, int z) {
  for (int i = y, j = z; i >= 1; i--) {
    while ((h.at(j) >= h.at(i) * 2) && brr[i] != 1 && brr[j] != 1) {
      cnt++;
      brr[i] = 1;
      brr[j] = 1;
      if (brr[j] == 1) {
        j--;
      }
    }
    if (brr[j] == 1) {
      j--;
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    scanf("%d", &arr[i]);
  }
  sort(arr + 1, arr + n + 1);

  return 0;
}