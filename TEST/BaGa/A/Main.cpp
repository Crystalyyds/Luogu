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
//     // 基线条件
//     if (left == right)
//         return left;

//     // 递归条件
//     if (left < right)
//     {
//         int mid = (left + right) / 2; // 得到中间值
//         if (x < p[mid])               // 小于，改变right
//             return fun(p, x, left, mid - 1);
//         else if (x > p[mid]) // 大于，改变left
//             return fun(p, x, mid + 1, right);
//         else
//             return mid; // 得到x
//     }
//     return -1;
// }
// int main()
// {
//     return 0;
// }