#include <bits/stdc++.h>
using namespace std;
string ss;
int n, cnt, op;
int main()
{
    cin >> n;
    while (n--)
    {
        cnt = 0;
        cin >> op;
        cin >> ss;
        if (ss == "")
        {
            cout << 0 << endl;
            continue;
        }
        int size = ss.size();
        for (int i = 0; i < op / 2; i++)
        {
            if ((ss[i] == '0' && ss[op - 1 - i] == '1') || (ss[i] == '1' && ss[op - 1 - i] == '0'))
            {
                // cout << ss[i] << "    " << ss[op - 1 - i] << endl;
                // cout << i << " " << op - 1 - i << endl;
                cnt++;
            }
            else
            {
                break;
            }
        }
        cout << op - cnt * 2 << endl;
    }

    return 0;
}
