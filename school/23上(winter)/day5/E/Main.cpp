#include <bits/stdc++.h>
using namespace std;
const int T = 5;
typedef pair<int, int> PII;
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
int path[5][5];
int judge[5][5];
map<int, PII> brr;
void fun(int a, int b)
{
    queue<PII> arr;
    arr.push({a, b});

    memset(judge, -1, sizeof judge);
    path[1][1] = 0;
    while (!arr.empty())
    {
        auto start = arr.front();
        arr.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = start.first + dx[i];
            int y = start.second + dy[i];
            if (x >= 1 && x <= 5 && y >= 1 && y <= 5 && path[x][y] == 0 &&
                judge[x][y] == -1)
            {

                judge[x][y] = judge[start.first][start.second] + 1;
                arr.push({x, y});
            }
        }
    }
    cout << judge[5][5];
}
int main()
{
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> path[i][j];
        }
    }

    fun(0, 0);
    cout << judge[5][5] << endl;
    return 0;
}