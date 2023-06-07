#include <bits/stdc++.h>
using namespace std;
const int T = 110;
int n, m, f[T], v[T], w[T], s[T];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> v[i] >> w[i] >> s[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int z = 1; z <= s[i] && z * v[i] <= j; z++)
            {
                f[j] = max(f[j], f[j - z * v[i]] + w[i] * z);
            }
        }
    }
    cout << f[m];
}
