#include <bits/stdc++.h>
using namespace std;
//¿ìÅÅ

int n, arr[100010];
void fun(int arr[], int l, int r) {
  if (l >= r) return;
  int i = l;
  int j = r;
  int mid = arr[(l + r) / 2];
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
  cin >> n;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  fun(arr, 1, n);
  for (int i = 1; i <= n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}