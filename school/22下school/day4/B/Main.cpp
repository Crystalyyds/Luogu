#include <bits/stdc++.h>
using namespace std;
int n;
int brr[5];

int main() {
  cin >> n;
  int arr[3] = {2, 3, 5};
  for (int i = 0; i < 3; i++) {
    if (n % arr[i] == 0) {
      brr[i] = 2 * n;
    }
  }
}