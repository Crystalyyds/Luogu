#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int main()
{
    cin >> T;
    while (T--)
    {
        ll n, k;
        cin >> n >> k;
        if (n % 2 == 0 || n % k == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        else if (n < 2 + k)
        {
            cout << "NO" << endl;
            continue;
        }
        else
        {
            for (int i = 1; n >= 0; i++)
            {
                n -= i * k;
                if (n % 2 == 0)
                {
                    cout << "YES" << endl;
                    continue;
                }
            }
            cout << "NO" << endl;
        }
    }
}