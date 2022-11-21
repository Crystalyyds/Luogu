#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 1000010;

int n, m;
char p[N], s[M];
int Next[N];

int main() {
  cin >> n >> p + 1 >> m >> s + 1;
  for (int i = 2, j = 0; i <= n; i++) {
    while (j && p[i] != p[j + 1]) j = Next[j];
    if (p[i] == p[j + 1]) j++;
    Next[i] = j;
  }
  for (int i = 1, j = 0; i <= m; i++) {
    while (j && s[i] != p[j + 1]) j = Next[j];
    if (s[i] == p[j + 1]) j++;
    if (j == n) {
      printf("%d ", i - n);
      j = Next[j];
    }
  }
  return 0;
}
