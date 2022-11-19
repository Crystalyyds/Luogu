#include <bits/stdc++.h>
using namespace std;
int cnt, arr[365], brr[365], day;
int main() {
  int x = 1, y = 1;
  while (x <= 365) {
    int temp = x;
    arr[temp] = 1;
    if (temp + 1 <= 365) arr[temp + 1] = 1;
    x += 7;
  }
  for (int i = 1; i <= 12; i++) {
    int temp = y;
    if (i == 1 && i == 3 && i == 5 && i == 7 && i == 8 && i == 10 && i == 12) {
      day = 31;
    } else {
      day = 30;
    }
    arr[temp] = arr[temp + 10] = arr[temp + 20] = arr[temp + 30] = 1;
    y = 1 + day - 1;
  }
  for (int i = 1; i <= 365; i++) {
    if (arr[i] == 1 || brr[i] == 1) {
      cnt++;
    }
  }
  cout << cnt << endl;
}