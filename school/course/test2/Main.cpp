#include <bits/stdc++.h>
using namespace std;
#define maxlength 11
class LCS
{
public:
    LCS(int nx, int ny, char *x, char *y) // �����ݳ�Աm��n��a��b��c��s��ʼ��
    {
        m = nx;
        n = ny;              // ��m��n��ֵ
        a = new char[m + 2]; // �����±�Ϊ0��Ԫ�غ��ַ����������
        b = new char[n + 2];
        memset(a, 0, m + 2);
        memset(b, 0, n + 2);
        c = new int[maxlength][maxlength]; // maxlengthΪĳ������ֵ
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
        c[i][0] = 0; // ��ʼ���б���б�Ϊ0��Ԫ��
    for (int j = 1; j <= n; j++)
        c[0][j] = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            if (a[i] == b[j]) // ��c[i-1][j-1]�õ�c[i][j]
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                s[i][j] = 1;
            }
            else if (c[i - 1][j] >= c[i][j - 1]) // ��c[i-1][j]�õ�c[i][j]
            {
                c[i][j] = c[i - 1][j];
                s[i][j] = 2;
            }
            else // ��c[i][j-1]�õ�c[i][j]
            {
                c[i][j] = c[i][j - 1];
                s[i][j] = 3;
            }
    return c[m][n]; // �������Ž�ֵ
}
void LCS::CLCS(int i, int j) const
{
    if (i == 0 || j == 0 || s[i][j] == 0)
        return; // ��ֹ����
    if (s[i][j] == 1)
    {
        CLCS(i - 1, j - 1);
        cout << a[i]; // ������Ž�ĵ�ǰ����
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
