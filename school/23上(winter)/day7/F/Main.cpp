#include <bits/stdc++.h>
using namespace std;
const int N = 50010;
int f[N];
int w[N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= w[i]; j--)
        {
            f[j] = max(f[j], f[j - w[i]] + w[i]);
        }
    }
    cout << f[n];
    return 0;
}