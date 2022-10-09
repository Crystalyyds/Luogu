#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87392609
int main() {
  char str[100];
  cin.get(str, 100);
  int count = 0;
  for (int i = 0; i < strlen(str); i++) {
    if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z') ||
        (str[i] >= '0' && str[i] <= '9')) {
      count++;
    }
  }
  cout << count << endl;
}