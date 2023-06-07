#include <iostream>
using namespace std;
#include <math.h>
#include <vector>

static int ii = 0;

bool Place(int k, int i, int *x) // 判定两个皇后是否在同一列或在同一斜线上
{
    for (int j = 0; j < k; j++)
        if ((x[j] == i) || (abs(x[j] - i) == abs(j - k)))
            return false;
    return true;
}

void NQueens(int k, int n, int *x) // 递归函数（求解n皇后问题）
{
    for (int i = 0; i < n; i++)
    {
        if (Place(k, i, x))
        {
            x[k] = i;
            if (k == n - 1)
            {
                ii++;
                cout << "(" << ii << ") ";
                for (i = 0; i < n; i++)
                {
                    cout << x[i] << " ";
                }
                cout << endl;
            }
            else
            {
                NQueens(k + 1, n, x);
            }
        }
    }
}
void NQueens(int n, int *x)
{
    NQueens(0, n, x);
}

int main()
{
    int x[8];
    for (int i = 0; i < 8; i++)
        x[i] = -1;
    NQueens(8, x);
}
