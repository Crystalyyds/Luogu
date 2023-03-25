#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
string arr[30];
int judge[30][60];
int mx = 0;
using namespace std;
void fun(int a, int b)
{
    queue<PII> brr;
    brr.push({a, b});
    int count = 1;

    judge[a][b] = 1;
    int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
    while (!brr.empty())
    {
        auto start = brr.front();
        brr.pop(); // µ¯³ö
        for (int i = 0; i < 4; i++)
        {
            int x = start.first + dx[i];
            int y = start.second + dy[i];
            if (x >= 0 && x < 30 && y >= 0 && y < 60 && arr[x][y] == '1' && judge[x][y] == 0)
            {
                judge[x][y] = 1;
                count++;
                brr.push({x, y});
            }
        }
    }
    mx = max(count, mx);
}

int main()
{
    for (int i = 0; i < 30; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 30; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            if (arr[i][j] == '1' && judge[i][j] == 0)
            {
                fun(i, j);
            }
        }
    }
    cout << mx << endl;
    return 0;
}
