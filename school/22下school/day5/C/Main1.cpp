#include <bits/stdc++.h>
using namespace std;
int n, cnt;
struct nums {
  int num;
  int key;
  int size;
  int brr[10];
} arr[6010];
nums fun(nums temp) {
  temp.size = 0;
  for (int i = 2; i <= sqrt(temp.num); i++) {
    if (temp.num % i == 0) {
      temp.brr[temp.size] = i;
      temp.size += 1;
      temp.key = 1;
    }
  }
  if (temp.size == 0) {
    temp.key = 0;
  }
  return temp;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].num;
    arr[i] = fun(arr[i]);
  }
  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      if (arr[i].key == 0 && arr[j].key == 0) {
        cnt++;
      } else {
        if (arr[i].num % arr[j].num == 0 || arr[j].num % arr[i].num == 0) {
          continue;
        }
        int ww = max(arr[i].size, arr[j].size);
        for (int p = 0; p <= ww; p++) {
          if (arr[i].brr[p] != arr[j].brr[p] &&
              (arr[i].brr[p] != 0 || arr[j].brr[p] != 0)) {
            cnt++;
            break;
          }
        }
      }
    }
  }
  cout << cnt;
  return 0;
}