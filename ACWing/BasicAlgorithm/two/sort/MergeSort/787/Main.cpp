#include <bits/stdc++.h>
using namespace std;
int n, arr[100010], brr[100010];
void fun(int arr[], int l, int r) {
  if (l >= r) return;
  int mid = l + r >> 1;
  fun(arr, l, mid);
  fun(arr, mid + 1, r);
  int i = l, j = mid + 1, k = 1;
  while (i <= mid && j <= r) {
    if (arr[i] <= arr[j]) {
      brr[k++] = arr[i];
      i++;
    } else {
      brr[k++] = arr[j];
      j++;
    }
  }
  while (i <= mid) {
    brr[k++] = arr[i];
    i++;
  }
  while (j <= r) {
    brr[k++] = arr[j];
    j++;
  }
  for (i = l, j = 1; i <= r; i++, j++) arr[i] = brr[j];
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
  }
  fun(arr, 1, n);
  for (int i = 1; i <= n; i++) {
    printf("%d ", arr[i]);
  }
  return 0;
}