#include <bits/stdc++.h>
using namespace std;
string str;
int cnt;
int main() {
  cin >> str;
  int size = str.length();
  int j = 0;
  for (int i = size - 1; i >= 0; i--) {
    int temp = 0;
    temp = str[j] - '0';
    cnt += temp * pow(8, i);
    j++;
  }
  cout << cnt;
  return 0;
}