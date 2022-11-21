#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/problem/P3375
char a[1000010], b[1000010];
int nt[1000010];
int ww = 0;
int main()
{
    cin >> a + 1;
    cin >> b + 1;
    int n = strlen(a + 1);
    int m = strlen(b + 1);
    for (int i = 2, j = 0; i <= m; i++)
    {
        while (j && b[i] != b[j + 1])
            j = nt[j];
        if (b[i] == b[j + 1])
            j++;
        nt[i] = j;
    }
    for (int i = 1, j = 0; i <= n; i++)
    {
        while (j && a[i] != b[j + 1])
        {
            j = nt[j];
        }
        if (a[i] == b[j + 1])
            j++;
        if (j == m)
        {
            cout << i - m + 1 << endl;
            j = nt[j];
            ww = 1;
        }
    }
    if (ww == 0)
    {
        cout << -1;
    }
    return 0;
}

//ÊäÈë
// ABABABC
// ABA

//Êä³ö
// 1
// 3

// nt
// 0 0 1