#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, cnt, temp;
int main()
{
    cin >> n;
    while (n != 0)
    {
        temp = 0;
        if (n == 2)
        {
            cnt += 2;
            break;
        }
        if (n == 1)
        {
            cnt += 1;
            break;
        }
        for (ll i = 2; i < n; i++)
        {
            if (n % i == 0)
            {
                n -= max(i, n / i);
                break;
            }
        }
        cnt++;
    }
    if (cnt % 2 == 0)
        cout << "kou";
    else
        cout << "yukari";
    return 0;
}