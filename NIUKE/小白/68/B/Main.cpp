#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
map<int, int> mp;
ll T, n, k, a, b, temp, x, y, op, op1;
int main()
{
    cin >> T;
    while (T--)
    {
        mp.clear();
        cin >> n >> a >> b;
        mp[a] = b;
        op1 = 1e9 + 10;
        for (int i = 0; i < n; i++)
        {
            cin >> k >> x >> y;
            mp[x] = y;
            op = 1e9 + 10;
            for (int j = 0; j < k; j++)
            {
                cin >> temp;
                if (temp >= max(a, x))
                {
                    temp = temp - (b + y);
                }
                else if (temp >= min(a, x))
                {
                    temp = temp - mp[min(a, x)];
                }
                if (temp < 0)
                    temp = 0;
                op = min(temp, op);
            }
            op1 = min(op, op1);
        }
        cout << op1 << endl;
    }
    return 0;
}