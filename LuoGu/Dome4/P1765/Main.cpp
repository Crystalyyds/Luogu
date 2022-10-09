#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87665307
int main() {
  string str;
  int count = 0;
  getline(cin, str);
  int arr[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3, 1, 2, 3, 1,
                 2, 3, 1, 2, 3, 4, 1, 2, 3, 1, 2, 3, 4};
  for (int i = 0; i < str.length(); i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      count += arr[str[i] - 'a'];
    } else if (str[i] == ' ') {
      count++;
    }
  }
  cout << count << endl;
  return 0;
}