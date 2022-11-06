#include <bits/stdc++.h>
using namespace std;
int n, m, arr[100010];
void fun(int arr[], int l, int r) {
  if (l >= r) return;
  int i = l, j = r, mid = arr[(l + r) >> 1];
  while (i <= j) {
    while (arr[i] < mid) i++;
    while (arr[j] > mid) j--;
    if (i <= j) {
      swap(arr[i], arr[j]);
      i++;
      j--;
    }
  }
  fun(arr, l, j);
  fun(arr, i, r);
}
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  fun(arr, 1, n);
  cout << arr[m];
  return 0;
}