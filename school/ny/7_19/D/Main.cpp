#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
typedef long long ll;

ll a[N], b[N], c[N];
int n, t;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = b[i - 1] + a[i];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        memcpy(c, a, sizeof c);
        for (int j = 3; j + i <= n; j++)
        {
            cnt = max(cnt, b[])
        }
    }
}
