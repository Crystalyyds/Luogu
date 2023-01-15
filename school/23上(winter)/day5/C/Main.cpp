#include <bits/stdc++.h>
using namespace std;
const int T = 15;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int n, m, bx, by, ex, ey;
char path[T][T];
int judge[T][T];
typedef pair<int, int> PII;
void fun(int a, int b)
{
    queue<PII> arr;
    arr.push({a, b});
    memset(judge, -1, sizeof(judge));
    judge[a][b] = 0;
    while (!arr.empty())
    {
        auto temp = arr.front();
        arr.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = temp.first + dx[i];
            int y = temp.second + dy[i];
            if (x >= 1 && x <= n && y >= 1 && y <= m && path[x][y] != '*' && judge[x][y] == -1)
            {
                judge[x][y] = judge[temp.first][temp.second] + 1;
                arr.push({x, y});
            }
        }
    }
    if (judge[ex][ey] == -1)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;
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
            if (path[i][j] == 'S')
                bx = i, by = j;
            if (path[i][j] == 'T')
                ex = i, ey = j;
        }
    }
    fun(bx, by);
    return 0;
}