#include <bits/stdc++.h>
using namespace std;
int n, a, b, temp = 0;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    while (n--)
    {
        temp = 0;
        int num = 1;
        cin >> a >> b;
        a = max(a, b);
        if (a == 0)
        {
            cout << 0 << endl;
            continue;
        }
        while (a > 0)
        {
            if (temp % 2 == 0 && temp != 0)
            {
                num += 2;
            }
            a = a - num;
            temp++;
        }
        cout << temp << endl;
    }
}