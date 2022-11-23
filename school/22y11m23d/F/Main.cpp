#include <bits/stdc++.h>
using namespace std;
vector<int> arr;
int dx[2] = {0, 1}, dy[2] = {1, 0};
int n, m, bu, ve;
int path[100][100];
int num[100][100];
void fun(int a, int b)
{
    ve += path[a][b];
    if (bu == n)
    {
        arr.push_back(ve);
    }
    for (int i = 0; i < 2; i++)
    {
        num[a][b] = 1;
        int x = a + dx[i];
        int y = b + dy[i];
        if (x <= n - 1 && y >= n - 1 && num[x][y] == 0)
        {
            fun(x, y);
            bu++;
        }
        bu--;
        num[a][b] = 0;
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &path[i][j]);
        }
    }
    fun(0, 0);
    cout << arr.size() << endl;
    return 0;
}