#include <bits/stdc++.h>
using namespace std;
int fun(int n) {
  int a = sqrt(n);
  if (n == 0 || n == 1) return 0;
  for (int i = 2; i <= a; i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int main() {
  char array[100], arr[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                              0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  scanf("%s", array);
  int len = strlen(array);
  for (int i = 0; i < len; i++) {
    int key = array[i] - 'a';
    arr[key] += 1;
  }
  int max = arr[0];
  for (int i = 1; i < 26; i++) {
    if (arr[i] > max && arr[i] != 0) {
      max = arr[i];
    }
  }
  int min = max;
  for (int i = 1; i < 26; i++) {
    if (arr[i] < min && arr[i] != 0) {
      min = arr[i];
    }
  }
  if (fun(max - min) == 1) {
    cout << "Lucky Word" << endl;
    cout << max - min << endl;
  } else {
    cout << "No Answer" << endl;
    cout << max - min << endl;
  }
}