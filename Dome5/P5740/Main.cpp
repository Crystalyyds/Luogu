#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87947098
struct Student {
  string name;
  int a, b, c;
};
Student arr[1010];
int n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
  }
  int max = arr[0].a + arr[0].b + arr[0].c;
  int op = 0;
  int num = n + 1;
  for (int i = 1; i < n; i++) {
    int temp = arr[i].a + arr[i].b + arr[i].c;
    if (temp > max) {
      max = temp;
      num = i;
    }
  }
  for (int i = 0; i < n; i++) {
    int temp = arr[i].a + arr[i].b + arr[i].c;
    if (i != num) {
      if (temp == max) {
        num = min(i, num);
      }
    }
  }
  cout << arr[num].name << " " << arr[num].a << " " << arr[num].b << " "
       << arr[num].c << endl;
  return 0;
}