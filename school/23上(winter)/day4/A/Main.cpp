#include <bits/stdc++.h>
using namespace std;

const int N = 50010;

int n, m, x, y, num, cnt;
int p[N];

int find(int x) 
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void connect(int a, int b)
{
    if (find(a) == find(b))
        return;
    else
    {
        p[find(b)] = find(a);
        cnt--;
    }
}

int main()
{

    while (true)
    {
        cin >> n >> m;
        if (n == m && n == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            p[i] = i;
        }

        cnt = n;
        num++;
        while (m--)
        {
            cin >> x >> y;
            connect(x, y);
        }
        cout << "Case " << num << ": " << cnt << endl;
    }
    return 0;
}