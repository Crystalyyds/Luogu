// อุฦห
#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int e[N], h[N], ne[N], idx;
int d[N], n, m;
int q[N], hh = 0, tt = -1;
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

int fun()
{
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
        {
            q[++tt] = i;
        }
    }
    while (tt >= hh)
    {
        int a = q[hh++];
        for (int i = h[a]; i != -1; i = ne[i])
        {
            int j = e[i];
            d[j]--;
            if (!d[j])
                q[++tt] = j;
        }
    }
    if (tt == n - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        d[b]++;
        add(a, b);
    }
    if (fun())
    {
        for (int i = 0; i < n; i++)
        {
            cout << q[i] << " ";
        }
    }
    else
    {
        cout << "-1" << endl;
    }
    return 0;
}
