#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll T = 30;
typedef pair<ll, ll> PII;
ll n, m;
ll w[T], v[T];
ll f[30010];
int main()
{
    freopen("happy.in", "r", stdin);
    freopen("happy.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> v[i] >> w[i];
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = n; j >= v[i]; j--)
        {
            f[j] = max(f[j], f[j - v[i]] + w[i] * v[i]);
        }
    }
    cout << f[n];
    return 0;
}