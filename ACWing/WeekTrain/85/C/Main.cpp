#include <bits/stdc++.h>
using namespace std;
const int N = 100;
int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        p[find(a)] = find(b);
    }
    long long res = 1;
    for (int i = 1; i <= n; i++)
        if (p[i] != i)
            res *= 2;
    cout << res;
    return 0;
}