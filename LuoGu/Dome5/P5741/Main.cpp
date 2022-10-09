#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87982456
struct Stu {
  string name;
  int c, m, e;
} a[1010];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i].name >> a[i].c >> a[i].m >> a[i].e;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = i + 1; j <= n; j++) {
      int ans = abs(a[i].c - a[j].c);
      int ans1 = abs(a[i].m - a[j].m);
      int ans2 = abs(a[i].e - a[j].e);
      int ans3 = abs(a[i].e + a[i].c + a[i].m - a[j].c - a[j].m - a[j].e);
      if (ans <= 5 && ans1 <= 5 && ans2 <= 5 && ans3 <= 10) {
        if (a[i].name > a[j].name)
          cout << a[j].name << " " << a[i].name << "\n";
        else
          cout << a[i].name << " " << a[j].name << "\n";
      }
    }
  }
  return 0;
}

// #include <bits/stdc++.h>
// using namespace std;
// struct Student {
//   string name;
//   int a, b, c;
// };
// Student arr[1010];
// int n;
// int main() {
//   cin >> n;
//   for (int i = 0; i < n; i++) {
//     cin >> arr[i].name >> arr[i].a >> arr[i].b >> arr[i].c;
//   }
//   for (int i = 0; i < n; i++) {
//     for (int j = i + 1; j < n; j++) {
//       if (abs(arr[i].a - arr[j].a) <= 5 && abs(arr[i].b - arr[j].b <= 5) &&
//           abs(arr[i].c - arr[j].c) <= 5 &&
//           abs((arr[i].a + arr[i].b + arr[i].c) -
//               (arr[j].a + arr[j].b + arr[j].c)) <= 10) {
//         if (arr[i].name > arr[j].name) swap(arr[i].name, arr[j].name);
//         cout << arr[i].name << " " << arr[j].name << endl;
//       }
//     }
//   }
//   return 0;
// }