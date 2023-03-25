#include <bits/stdc++.h>
using namespace std;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
char path[30][30], judge[30][30];
int n, m, xx, yy;
void fun(int x, int a, int b)
{

    if (x == 0)
    {
        // cout << "??" << endl;
        judge[a][b] = '.';
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int temp = x;
        xx = a + dx[i];
        yy = b + dy[i];
        if (xx < 1 || xx > n || yy < 1 || yy > m)
        {
            continue;
        }
        judge[xx][yy] = '.';
        // cout << "??" << endl;
        if (temp-- >= 0)
            fun(temp--, xx, yy);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> path[i][j];
            judge[i][j] = path[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (path[i][j] >= '1' && path[i][j] <= '9')
            {
                fun(path[i][j] - '0', i, j);
                judge[i][j] = '.';
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << judge[i][j];
        }
        cout << endl;
    }
    return 0;
}