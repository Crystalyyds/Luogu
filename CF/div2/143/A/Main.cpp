#include <bits/stdc++.h>
using namespace std;
const int T = 1e3 + 10;
int op, n, m;
string a, b;
bool key = false;
int main()
{
    cin >> op;
    while (op--)
    {
        queue<char> x, y;
        cin >> n >> m;
        cin >> a;
        cin >> b;
        for (int i = 1; i < n; i++)
            if (a[i] == a[i - 1])
                x.push(a[i]);
        for (int i = 1; i < m; i++)
            if (b[i] == b[i - 1])
                y.push(a[i]);
        while (!x.size() == 0 && !y.size() == 0)
        {
            if (x.front() != y.back())
                x.pop();
            else if (y.front() != x.back())
                y.pop();
            else
            {
                cout << "NO" << endl;
                break;
            }
        }
        // cout << x.size() << "   " << y.size();
        cout << "YES" << endl;
    }
    return 0;
}