#include <iostream>

using namespace std;
typedef struct CLinkList {
  int data;
  struct CLinkList *next;
} node;

int main() {
  ///����ѭ������
  node *L, *r, *s;
  L = new node;  //����һ����תվ
  r = L;  //��ʱû�����ݣ���ѭ���вŻ������� r.data = l.data=-1;
  int n, k, m;
  cin >> n >> k >> m;
  for (int i = 1; i <= n; i++) {
    s = new node;  // r��ʼ������
    s->data = i;
    r->next = s;
    r = s;
  }
  r->next = L->next;  //�����һ�����ָ���һ�������ݽ��
  node *p;
  p = L->next;
  delete L;  //ɾ����һ���յĽ��
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