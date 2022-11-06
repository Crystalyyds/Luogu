#include <bits/stdc++.h>
using namespace std;
long long n;
int arr[1000];
int main() {
  scanf("%d", &n);
  int i = 2;
  int j = 0;
  cout << n << "=";
  while (n > i) {
    if (n % i == 0) {
      cout << i << "*";
      n /= i;
    } else
      i++;
  }
  cout << i;
  return 0;
}