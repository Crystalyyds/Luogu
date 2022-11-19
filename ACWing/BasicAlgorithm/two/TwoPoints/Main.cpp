#include <bits/stdc++.h>
using namespace std;
//¶þ·Ö£¨Two points£©
int arr[100];
int main() {
  for (int i = 1; i <= 100; i++) {
    arr[i] = (rand() % (100 - 1 + 1)) + 1;
  }
  int index = (rand() % (100 - 1 + 1)) + 1;
  cout << "==========================" << endl;
  int temp = arr[index];
  cout << temp << endl;
  sort(arr + 1, arr + 101);
  int l = 1, r = 100;
  while (l <= r) {
    int mid = arr[(l + r) / 2];
    cout << mid << endl;
    cout << endl;
    // >>1 == /2
    if (temp == mid) {
      l = mid;
      break;
    }
    if (temp >= mid) {
      l = mid;
    } else {
      r = mid - 1;
    }
  }
  cout << l << endl;
  if (l != index) {
    cout << "false" << endl;
  } else {
    cout << "ture" << endl;
  }
  return 0;
}