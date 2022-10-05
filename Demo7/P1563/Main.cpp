#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/88704355
int m, n;
struct people {
  int num;
  string name;
} arr[100010];
int id = 1;
int main() {
  people temp = {0, ""};
  cin >> m >> n;
  for (int i = 1; i <= m; i++) {
    cin >> arr[i].num >> arr[i].name;
  }
  for (int i = 1; i <= n; i++) {
    int tn, tm;
    cin >> tn >> tm;
    if (arr[id].num == tn) {
      if (id - tm < 1) {
        id = id + m - tm;
        temp.num = arr[id].num;
        temp.name = arr[id].name;
      } else {
        id = id - tm;
        temp.num = arr[id].num;
        temp.name = arr[id].name;
      }
    } else {
      if (id + tm > m) {
        id = id - m + tm;
        temp.num = arr[id].num;
        temp.name = arr[id].name;
      } else {
        id = id + tm;
        temp.num = arr[id].num;
        temp.name = arr[id].name;
      }
    }
  }
  cout << temp.name << endl;
  return 0;
}
