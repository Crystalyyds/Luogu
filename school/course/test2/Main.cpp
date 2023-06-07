#include <bits/stdc++.h>
using namespace std;
#define maxlength 11
class LCS
{
public:
    LCS(int nx, int ny, char *x, char *y) // 对数据成员m、n、a、b、c、s初始化
    {
        m = nx;
        n = ny;              // 对m和n赋值
        a = new char[m + 2]; // 考虑下标为0的元素和字符串结束标记
        b = new char[n + 2];
        memset(a, 0, m + 2);
        memset(b, 0, n + 2);
        c = new int[maxlength][maxlength]; // maxlength为某个常量值
        s = new int[maxlength][maxlength];
    }
    int LCSLength();
    void CLCS()
    {
    }

private:
    void CLCS(int i, int j) const;
    int (*c)[maxlength], (*s)[maxlength];
    int m, n;
    char *a, *b;
};
int LCS::LCSLength()
{
    for (int i = 0; i <= m; i++)
        c[i][0] = 0; // 初始化行标或列标为0的元素
    for (int j = 1; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j]) // 由c[i-1][j-1]得到c[i][j]
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1]) // 由c[i-1][j]得到c[i][j]
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 2;
            }
            else // 由c[i][j-1]得到c[i][j]
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 3;
            }
    return c[m][n]; // 返回最优解值
}
void LCS::CLCS(int i, int j) const
{
    if (i == 0 || j == 0 || s[i][j] == 0)
        return; // 终止条件
    if (s[i][j] == 1)
    {
        CLCS(i - 1, j - 1);
        cout << a[i]; // 输出最优解的当前分量
    }
    else if (s[i][j] == 2)
        CLCS(i - 1, j);
    else
        CLCS(i, j - 1);
}
int main()
{
    int nx, ny;
    char *x, *y;
    nx = 6, ny = 6;
    x = new char[nx], y = new char[ny];
    for (int i = 0; i < nx; i++)
    {
        cin >> x[i];
    }
    for (int i = 0; i < ny; i++)
    {
        cin >> y[i];
    }
    LCS lcs(nx, ny, x, y);
    lcs.CLCS();
    delete[] x;
    delete[] y;
    return 0;
}
