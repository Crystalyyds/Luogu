#include <bits/stdc++.h>
using namespace std;
int digit;
int main() {
  int i, j, k;
  int N;
  while (~scanf("%d/n", &N)) {
    int a[50000];             //�������ֵ���׳˵�ֵΪ����
    memset(a, 0, sizeof(a));  //�����ʼ��
    a[0] = 1;
    int digit = 1;  // �����λ��
    int up = 0;     //��λ
    int temp;
    for (i = 2; i <= N; i++)  //��׳�
    {
      for (j = 0; j < digit;
           j++)  //��ǰֵ��ÿһλ�˽׳˵���������13*8->3*8->1*8+2
      {
        temp = a[j] * i + up;
        a[j] = temp % 10;
        up = temp / 10;
      }
      while (up)  //������λ�н�λ�������λ����
      {
        a[digit] = up % 10;
        up = up / 10;
        digit++;
      }
    }
    for (i = digit - 1; i >= 0; i--) {
      printf("%d", a[i]);
    }
    printf("\n");
  }
}