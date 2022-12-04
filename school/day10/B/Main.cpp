#include <bits/stdc++.h>
using namespace std;
const int N = 130;
int n, arr[N][N], brr[N], crr[N];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &arr[i][j]);
            arr[i][j] = arr[i][j] + arr[i - 1][j];
        }
    }
    cout << "==============" << endl;
    int m = n, j = 1, mx = 0;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            crr[j] = arr[n][j] - arr[i][j];
            crr[j] = crr[j] + crr[j - 1];
            cout << crr[j] << " ";
        }
        cout << endl;
        for (int j = 1; j <= n; j++)
        {
            for (int z = j; z <= n; z++)
            {
                int temp = crr[z] - crr[z - j];
                cout << temp << " ";
                mx = max(temp, mx);
            }
            cout << endl;
        }
        cout << "==============" << endl;
    }
    return 0;
}