// #include <bits/stdc++.h>
// using namespace std;
// typedef struct
// {
//     int n;
//     int maxLength;
//     // ElemType *element;
// } listSet;

// int fun(listSet *p, int x, int left, int right)
// {
//     // ��������
//     if (left == right)
//         return left;

//     // �ݹ�����
//     if (left < right)
//     {
//         int mid = (left + right) / 2; // �õ��м�ֵ
//         if (x < p[mid])               // С�ڣ��ı�right
//             return fun(p, x, left, mid - 1);
//         else if (x > p[mid]) // ���ڣ��ı�left
//             return fun(p, x, mid + 1, right);
//         else
//             return mid; // �õ�x
//     }
//     return -1;
// }
// int main()
// {
//     return 0;
// }