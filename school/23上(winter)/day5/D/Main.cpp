#include <iostream>
using namespace std;
const int T = 110;
int n, m, cnt, temp;
char path[T][T];
void fun(int a, int b)
{
    for (int i = -1; i <= 1; i++)
    {
        for (int j = -1; j <= 1; j++)
        {
            int x = a + i;
            int y = b + j;
            if (x >= 1 && x <= n && y >= 1 && y <= m && path[x][y] == 'W')
            {
                path[a][b] = '.';
                fun(x, y);
            }
        }
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
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (path[i][j] == 'W')
            {
                cnt++;
                fun(i, j);
            }
        }
    }
    cout << cnt << endl;
    return 0;
}