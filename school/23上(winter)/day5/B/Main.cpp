#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int n, m, x, y, bx, by, cnt = 1;
char path[N][N];
int fun(int a, int b)
{
    path[a][b] = '#';
    for (int i = 0; i < 4; i++)
    {
        x = a + dx[i], y = b + dy[i];
        if (x >= 1 && x <= n && y >= 1 && y <= m && path[x][y] == '.')
        {
            cnt += 1;
            fun(x, y);
        }
    }
    return cnt;
}
int main()
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> path[i][j];
            if (path[i][j] == '@')
            {
                bx = i;
                by = j;
            }
        }
    }
    cout << fun(bx, by);
    return 0;
}
