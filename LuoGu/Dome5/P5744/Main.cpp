#include <bits/stdc++.h>
using namespace std;
int n;
// https://www.luogu.com.cn/record/87994746
struct person {
  string name;
  int age;
  int count;
} arr[10];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i].name >> arr[i].age >> arr[i].count;
    if (arr[i].count % 5 != 0) {
      cin.clear();
      cin >> arr[i].name >> arr[i].age >> arr[i].count;
    }
    arr[i].age += 1;
    if (arr[i].count != 0) {
      if (arr[i].count * 1.2 <= 600) {
        arr[i].count = arr[i].count * 1.2;
      } else {
        arr[i].count = 600;
      }
    } else {
      arr[i].count = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << arr[i].name << " " << arr[i].age << " " << arr[i].count << endl;
  }
  return 0;
}