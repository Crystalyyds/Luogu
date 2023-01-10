#include <bits/stdc++.h>
using namespace std;
long long arr[100010], brr[100010], crr[100010];
int n, m;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        crr[i] = arr[i] + crr[i - 1];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        brr[i] = arr[i] + brr[i - 1];
    }
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1)
        {
            cout << crr[z] - crr[y - 1] << endl;
        }
        else
        {
            cout << brr[z] - brr[y - 1] << endl;
        }
    }
    return 0;
}