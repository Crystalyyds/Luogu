#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, x, cnt;
int main()
{
    cin >> n;
    while (n--)
    {
        cnt = 0;
        cin >> a >> b >> c >> d;
        if (d < b)
        {
            cout << -1 << endl;
            continue;
        }
        x = d - b;
        a += x;
        cnt += x;
        if (a >= c)
            cnt += (a - c);
        else
            cnt = -1;
        cout << cnt << endl;
    }
    return 0;
}