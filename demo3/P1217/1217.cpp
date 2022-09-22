#include <bits/stdc++.h>
#include <math.h>
using namespace std;
string s;
int fun(int n) {
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      return 0;
    }
  }
  return 1;
}
int fun1(int n) {
  s = to_string(n);
  int cun = s.size();
  char array[cun + 1];
  strcpy(array, s.c_str());
  if (cun % 2 == 0) {
    int count = 0;
    for (int i = 0; i < cun / 2; i++) {
      if (array[i] == array[cun - i - 1]) {
        count++;
      }
    }
    if (count == cun / 2) {
      return 1;
    }
  } else {
    int count = 0;
    for (int i = 0; i < cun / 2; i++) {
      if (array[i] == array[cun - i - 1]) {
        count++;
      }
    }
    if (count == cun / 2) {
      return 1;
    }
  }
  return 0;
}
int main() {
  int a, b;
  cin >> a >> b;
  for (int i = a; i <= b; i++) {
    if (fun(i) == 1) {
      if (i < 10) {
        cout << i << endl;
      } else {
        if (fun1(i) == 1) {
          cout << i << endl;
        }
      }
    }
  }
}