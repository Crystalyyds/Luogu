#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int m, p, q, k, res;
typedef pair<int, int> PII;
PII a[N], b[N];
bool a1[N], b1[N];

int fun(int x, int z)
{
    if (z > m)
    {
        return res;
    }
    for (int i = 1; i <= p; i++)
    {
        if (!b1[i])
        {
            b1[i] = true;
            res = fun(x, z + b[i].second) + fi
        }
    }
}

int main()
{
    cin >> m >> p >> q >> k;
    for (int i = 1; i <= p; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 1; i <= q; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
    for (int i = 1; i <= q; i++)
        int cnt = max(fun(i, m - a[i].second) + a[i].first, cnt);
}
