#include <bits/stdc++.h>
using namespace std;
struct one {
  int age;
  int index;
  string op;
} arr[110];
int n;
bool fun(one a, one b) {
  if (a.age != b.age) {
    return a.age > b.age;
  } else {
    return a.index < b.index;
  }
}
bool fun1(one a, one b) {
  if ((a.age < 60 && b.age < 60) || a.age == b.age) {
    return a.index < b.index;
  } else {
    return a.age > b.age;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].op >> arr[i].age;
    arr[i].index = i;
  }
  int ww = 0;
  sort(arr + 1, arr + 1 + n, fun);
  for (int i = 1; i <= n; i++) {
    if (arr[i].age >= 60) {
      cout << arr[i].op << endl;
    } else {
      ww = i;
      sort(arr + i, arr + n + 1, fun1);
      break;
    }
  }
  for (int i = ww; i <= n; i++) {
    cout << arr[i].op << endl;
  }
}
