#include <bits/stdc++.h>
using namespace std;
int arr[1010][1010], brr[1010][1010];
int n, m, op;

int main()
{
    cin >> n >> m >> op;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            brr[i][j] = brr[i - 1][j] + brr[i][j - 1] + arr[i][j] - brr[i - 1][j - 1];
        }
    while (op--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        cout << brr[c][d] + brr[a - 1][b - 1] - brr[a - 1][d] - brr[c][b - 1] << endl;
    }
}