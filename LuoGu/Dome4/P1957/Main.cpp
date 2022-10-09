#include <bits/stdc++.h>
// https://www.luogu.com.cn/record/87295096
using namespace std;
int main() {
  int N;
  int a, b, ans;
  char op;
  scanf("%d", &N);
  for (int i = 0; i < N; i++) {
    if (!(cin >> a)) {
      cin.clear();
      cin >> op >> a;
    }
    cin >> b;
    std::string str1 = std::to_string(a);
    std::string str2 = std::to_string(b);
    std::string stra = std::to_string(a + b);
    std::string strb = std::to_string(a - b);
    std::string strc = std::to_string(a * b);
    int counta = str1.size() + str2.size() + stra.size() + 2;
    int countb = str1.size() + str2.size() + strb.size() + 2;
    int countc = str1.size() + str2.size() + strc.size() + 2;
    switch (op) {
      case 'a':
        cout << a << '+' << b << '=' << a + b << endl;
        cout << counta << endl;
        break;
      case 'b':
        cout << a << '-' << b << '=' << a - b << endl;
        cout << countb << endl;
        break;
      case 'c':
        cout << a << '*' << b << '=' << a * b << endl;
        cout << countc << endl;
        break;
      default:
        break;
    }
  }

  return 0;
}
