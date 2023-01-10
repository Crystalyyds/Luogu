#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        scanf("%d", &m);
        int mi = 100010, ma = 0, x = 0, y = 0;
        for (int i = 1; i <= m; i++)
        {
            int t;
            scanf("%d", &t);
            if (t > ma)
            {
                ma = t;
                y = 1;
            }
            else if (t == ma)
                y++;
            if (t < mi)
            {
                mi = t;
                x = 1;
            }
            else if (t == mi)
                x++;
        }
        if (ma != mi)
            printf("%lld\n", 1ll * x * y * 2);
        else
            printf("%lld\n", 1ll * x * (x - 1));
    }
    return 0;
}