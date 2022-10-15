#include <bits/stdc++.h>
using namespace std;
long long n, m, arr[2000010];
// https://www.luogu.com.cn/record/89395871
void fun(long long arr[], long long l, long long r) {
  long long i = l, j = r, flag = arr[(l + r) / 2], temp;
  do {
    while (arr[i] < flag) {
      i++;
    }
    while (arr[j] > flag) {
      j--;
    }
    if (i <= j) {
      temp = arr[i];
      arr[i] = arr[j];
      arr[j] = temp;
      i++;
      j--;
    }
  } while (i <= j);
  if (l < j) fun(arr, l, j);
  if (r > i) fun(arr, i, r);
}
int main() {
  for (int i = 1; i <= m; i++) {
    cin >> arr[i];
  }
  fun(arr, 1, m);
  for (int i = 1; i <= m; i++) {
    cout << arr[i] << " ";
  }
  return 0;
}