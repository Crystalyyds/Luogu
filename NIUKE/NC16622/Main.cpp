#include <bits/stdc++.h>

using namespace std;
// https://ac.nowcoder.com/acm/problem/16622
int main() {
  int n;
  cin >> n;
  for (int i = n; i >= 0; i--) {
    int x;
    cin >> x;  // x��ϵ��,i��ָ��
    if (x == 0) continue;

    if (x < 0)
      cout << "-";
    else if (i != n && x > 0)
      cout << "+";

    if (abs(x) == 1 && i != 0)
      ;
    else
      cout << abs(x);

    if (i > 1)
      cout << "x^" << i;
    else if (i == 1)
      cout << "x";
  }
}

// 1.�Ƚ��ÿһ��ķ��ţ���������������+����-�����ж�ÿһ���ϵ����0�Ĺ�ϵ���ɡ�

// 2.�ٽ��ϵ�������⣬ϵ���ľ���ֵΪ1ʱ����Ҫ�������ָ��Ϊ0ʱ���⡣

// 3.�����x��ʽ�����⣬��ָ��������ۼ���