#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87889051
double fun(double x1, double y1, double x2, double y2) {
  return sqrt(abs((x1 - x2) * (x1 - x2)) + abs((y1 - y2) * (y1 - y2)));
}
int main() {
  double x1, y1, x2, y2, x3, y3, cnt = 0;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  cnt = fun(x1, y1, x2, y2) + fun(x2, y2, x3, y3) + fun(x3, y3, x1, y1);
  printf("%.2f", cnt);
  return 0;
}