#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
int n, m;
PII be, en;
char arr[100][100];
int nums[100][100];
int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
//вС об ср ио
void fun(int a, int b)
{
    queue<PII> brr;
    brr.push({a, b});
    memset(nums, -1, sizeof nums);
    nums[a][b] = 0;
    while (!brr.empty())
    {
        auto start = brr.front();
        brr.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = start.first + dx[i];
            int y = start.second + dy[i];
            if (x == -1)
                x = n - 1;
            if (y == -1)
                y = m - 1;
            if (x == n)
                x = 0;
            if (y == n)
                y = 0;
            if (arr[x][y] == 'D' && nums[x][y] == -1)
            {
                nums[x][y] = nums[start.first][start.second] + 1;
                brr.push({x, y});
            }
            else if (arr[x][y] == 'B' && nums[x][y] == -1)
            {
                nums[x][y] = nums[start.first][start.second] + 1;
                break;
            }
        }
    }
    cout << nums[en.first][en.second] << endl;
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'A')
                be = {i, j};
            if (arr[i][j] == 'B')
                en = {i, j};
        }
    }
    fun(be.first, be.second);
    for (int i = 0; i < n; i++)
    {

        for (int j = 0; j < m; j++)
        {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}