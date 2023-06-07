#include <bits/stdc++.h>
using namespace std;
map<int, int> m;
int n;
const int N = 1e5 + 10;
int a[N], b[N];
bool fun(int x, int y)
{
    return x > y;
}

int main()
{
    cin >> n;
    int t = n, op = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if (a[i] > n)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
        {
            if (m[a[i]] >= 1)
                t--;
            else
                b[op++] = a[i];
            m[a[i]] += 1;
        }
    }
    sort(b + 1, b + op);
    for (int i = 1; i + 1 <= op; i++)
    {
        // if (b[i ] - b[i-1] != 1 && i)
        // {
        //     cout << "NO" << endl;
        //     return 0;
        // }
        cout << b[i] << endl;
    }
    cout << "YES" << endl;
    return 0;
}