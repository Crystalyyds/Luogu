#include <bits/stdc++.h>
using namespace std;
int m, n, x, y, cnt, T;
const int a[] = {1, 2, 2, 1, -1, -2, -2, -1};
const int b[] = {2, 1, -1, -2, -2, -1, 1, 2};
bool judge[10][10];

void fun(int x, int y, int num)
{
    if (num == 0)
    {
        cnt++;
        return;
    }
    judge[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int xn = x + a[i], ym = y + b[i];
        if (xn >= 0 && xn < m && ym >= 0 && ym < n && !judge[xn][ym])
            fun(xn, ym, num - 1);
    }
    judge[x][y] = false;
}

int main()
{

    cin >> T;
    while (T--)
    {
        cin >> m >> n >> x >> y;
        judge[x][y] = true;
        fun(x, y, n * m - 1);
        cout << cnt << endl;
        cnt = 0;
        memset(judge, false, sizeof(judge));
    }
    return 0;
}
