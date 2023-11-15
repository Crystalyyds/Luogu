#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll n, m, op;

int main()
{
    cin >> op;
    while (op--)
    {
        string str;
        cin >> n >> m;
        cin >> str;
        if (m >= n)
        {
            for (ll i = 1; i <= n; i++)
                cout << 1;
            cout << endl;
            continue;
        }
        else
        {
            ll j = 0;
            // cout<<"OK"<<endl;
            bool key = false;
            for (int i = 0; i < n; i++)
            {
                if (key && str[i] == '1')
                {
                    m--;
                    key = false;
                    if (m == 0)
                    {
                        break;
                    }
                }
                if (str[i] == '0' && m)
                {
                    str[i] = '1';
                    key = true;
                }
            }
        }
        if (m != 1)
            cout << str << endl;
        else
        {
            if (str[n - 1] == '1')
                str[n - 1] = '0';
            else
                str[n - 1] = '1';
            cout << str << endl;
        }
    }
}