#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87441916
int fun(int array[7], int criteria[7]) {
  int num = 0;
  for (int i = 1; i <= 7; i++) {
    for (int j = 1; j <= 7; j++) {
      if (array[i] == criteria[j]) {
        num++;
      }
    }
  }
  return num;
}
int main() {
  int n;
  cin >> n;
  int criteria[7];
  int ticket[7] = {0, 0, 0, 0, 0, 0, 0};
  for (int i = 1; i <= 7; i++) {
    cin >> criteria[i];
  }
  for (int i = 1; i <= n; i++) {
    int array[7] = {0, 0, 0, 0, 0, 0, 0};
    for (int i = 1; i <= 7; i++) {
      cin >> array[i];
    }
    int temp = fun(array, criteria);
    if (temp) {
      ticket[temp] += 1;
    }
  }
  for (int i = 7; i >= 1; i--) {
    cout << ticket[i] << " ";
  }
}