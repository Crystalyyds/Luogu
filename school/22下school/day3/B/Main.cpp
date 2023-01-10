#include <bits/stdc++.h>
using namespace std;
string arr[5];
char op;
void fun(int m, int n) {
  int m0 = m, n0 = n;
  while (m % n != 0) {
    int temp = m;
    m = n;
    n = temp % n;
  }
  cout << n0 / n << "/" << m0 / n << endl;
}
int main() {
  string str;
  while (cin >> str) {
    int j = 0;
    for (int i = 0; i < str.length(); i++) {
      if (str[i] != '/' && (str[i] != '+' && str[i] != '-')) {
        arr[j] += str[i];
      } else {
        j++;
      }
      if (str[i] == '+' || str[i] == '-') {
        op = str[i];
      }
    }
    int brr[4] = {0, 0, 0, 0};
    for (int i = 0; i < 4; i++) {
      brr[i] = atoi(arr[i].c_str());
    }
    if (op == '-') {
      fun(brr[0] * brr[3] - brr[1] * brr[2], brr[2] * brr[4]);
    } else {
      fun(brr[0] * brr[3] + brr[1] * brr[2], brr[2] * brr[4]);
    }
  }
  return 0;
}