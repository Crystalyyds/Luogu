#include <bits/stdc++.h>
using namespace std;
int n, len, op, c[5];
typedef pair<int, int> PII;
string arr;
int main()
{
    cin >> n;
    while (n--)
    {

        cin >> arr;
        stack<int> stk;
        int a = 0, b = 0;
        memset(c, 0, sizeof(c));
        bool op = false;
        for (int i = 0; i < 5; i++)
        {
            c[i] = arr[i * 2 + 1] - arr[i * 2];
            stk.push(i);
            if (c[i] == -1)
                b++;
            if (c[i] == 1)
                a++;
            if ((a - b > 4 - i || b - a > 4 - i) && op == false)
            {
                cout << (i + 1) * 2 << endl;
                op = true;
                break;
            }
            if ((a - b == 4 - i || b - a == 4 - i) && op == false)
            {
                if (arr[(i + 1) * 2 + 1] - arr[(i + 1) * 2] == c[i])
                {
                    cout << i * 2 + 1 << endl;
                }
            }
        }
        if (a == b)
        {
            cout << -1 << endl;
            continue;
        }
    }
    return 0;
}