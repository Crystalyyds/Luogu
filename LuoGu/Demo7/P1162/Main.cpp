#include <bits/stdc++.h>
using namespace std;
const int N = 35;
typedef pair<int, int> PII;
int arr[N][N], n;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, -1, 0, 1};
void fun(int a, int b)
{
    if (arr[a][b] == 0)
        arr[a][b] = 3;
    queue<PII> que;
    que.push({a, b});
    while (!que.empty())
    {
        auto temp = que.front();
        que.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = temp.first + dx[i], y = temp.second + dy[i];
            if (x == -1)
                x = n - 1;
            if (y == -1)
                y = n - 1;
            if (x == n)
                x = 0;
            if (y == n)
                y = 0;
            if (arr[x][y] == 0)
            {
                arr[x][y] = 3;
                que.push({x, y});
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    fun(0, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == 3)
            {
                cout << 0 << " ";
            }
            else if (arr[i][j] == 0)
            {
                cout << 2 << " ";
            }
            else
            {
                cout << arr[i][j] << " ";
            }
        }
        cout << endl;
    }
}
