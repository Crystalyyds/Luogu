#include <bits/stdc++.h>
using namespace std;
// 数组实现trie===https://blog.csdn.net/weixin_42369779/article/details/105056985
int n, inex;
int arr[100010][26], cnt[100010];
char str[100010];
void insert(char *str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int u = str[i] - 'a';
    if (arr[p][u] == 0) {
      arr[p][u] = ++inex;
    }
    p = arr[p][u];
  }
  cnt[p]++;
}
int search(char *str) {
  int p = 0;
  for (int i = 0; str[i]; i++) {
    int u = str[i] - 'a';
    if (arr[p][u] == 0) {
      return 0;
    }
    p = arr[p][u];
  }

  return cnt[p];
}
int main() {
  cin >> n;
  while (n--) {
    char op[2];
    scanf("%s%s", op, str);
    if (*op == 'I')
      insert(str);
    else
      printf("%d\n", search(str));
  }
  return 0;
}