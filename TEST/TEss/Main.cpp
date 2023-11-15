#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll op, x, a, b;
void solve()
{
    ll cnt = 0;
    scanf("%lld%lld%lld", &x, &a, &b);
    while (x)
    {
        // cout << x << endl;
        if (x - sqrt(x + b) >= x - (x + a) / 2)
        {
            x = sqrt(x + b);
        }
        else if (x - (x + a) / 2 >= 1)
        {
            x = (x + a) / 2;
        }
        else
        {
            x -= 1;
        }
        cnt++;
    }
    printf("%lld\n", cnt);
}

int main()
{
    scanf("%d", &op);
    while (op--)
    {
        solve();
    }
}