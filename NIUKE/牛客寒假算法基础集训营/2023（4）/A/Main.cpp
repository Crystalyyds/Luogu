#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a, b;
int main()
{
    cin >> a >> b;
    if (a == b)
    {
        return 0;
    }
    else
    {
        if (a == 3 || b == 3)
        {
            cout << 3;
            return 0;
        }
        else
        {
            cout << min(a, b);
        }
    }
    return 0;
}