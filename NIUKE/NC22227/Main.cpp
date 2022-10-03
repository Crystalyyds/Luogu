#include <iostream>

using namespace std;
typedef struct CLinkList {
  int data;
  struct CLinkList *next;
} node;

int main() {
  ///建立循环链表
  node *L, *r, *s;
  L = new node;  //创建一个中转站
  r = L;  //此时没有数据，在循环中才会又数据 r.data = l.data=-1;
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    s = new node;  // r开始有数据
    s->data = i;
    r->next = s;
    r = s;
  }
  r->next = L->next;  //让最后一个结点指向第一个有数据结点
  node *p;
  p = L->next;
  delete L;  //删除第一个空的结点
  for (int i = 1; i <= n; i++) {
    if (p->data == k) {
      while (p->next != p) {
        for (int i = k; i < m - 1; i++) {
          p = p->next;
        }
        p->next = p->next->next;
        p = p->next;
      }
    }
    p = p->next;
  }
  cout << p->data << endl;
  return 0;
}