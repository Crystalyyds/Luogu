#include <iostream>

using namespace std;

const int N = 100010;

int n, m;
int p[N], cnt[N];  // cnt[ ]是表示大小的集合

int find(int x)  //查询祖宗结点
{
  if (p[x] != x) p[x] = find(p[x]);
  return p[x];
}

int main() {
  cin >> n >> m;

  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cnt[i] = 1;
  }

  while (m--) {
    string op;
    int a, b;
    cin >> op;

    if (op == "C") {
      cin >> a >> b;
      a = find(a), b = find(b);
      if (a != b) {
        p[a] = b;
        cnt[b] += cnt[a];  //执行合并操作
      }
    } else if (op == "Q1") {
      cin >> a >> b;
      if (find(a) == find(b))
        puts("Yes");
      else
        puts("No");
    } else {
      cin >> a;
      cout << cnt[find(a)] << endl;
    }
  }

  return 0;
}