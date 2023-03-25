#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, l1, r1, l2, r2, op, temp1, temp2, cnt;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> op;
        cin >> l1 >> r1;
        cin >> l2 >> r2;
        if (l1 > op || l2 > op)
        {
            cout << 0 << endl;
            continue;
        }
        temp1 = op - l1, temp2 = op - r1; // temp1 Da temp2 xiao
        if (temp2 > r2 || temp1 > r2)
        {
            cout << 0 << endl;
        }
        else
        {
            if (temp1 <= r2)
            {
                if (temp2 <= l1)
                    cnt = temp1 - l2 + 1;
                else
                    cnt = temp1 - temp2 + 1;
            }
            else
            {
                cnt = r2 - temp2 + 1;
            }
            if (cnt < 0)
            {
                cout << 0 << endl;
            }
            else
            {
                cout << cnt << endl;
            }
        }
    }
    return 0;
}