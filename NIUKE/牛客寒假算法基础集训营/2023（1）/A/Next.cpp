#include <bits/stdc++.h>
using namespace std;
int n, len, op;
typedef pair<int, int> PII;
string arr;
int main()
{
    cin >> n;
    while (n--)
    {
        PII temp;
        temp.first = temp.second = 0;
        cin >> arr;
        stack<int> s1, s2;
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] != '0')
            {
                if ((i + 1) % 2 == 1)
                    s1.push(i);
                else
                    s2.push(i);
            }
        }
        if (s1.size() == s2.size())
        {
            cout << -1 << endl;
            continue;
        }
        else
        {
            if (s1.size() > s2.size())
                op = s1.top();
            else
                op = s2.top();
        }
        if (op % 2 == 0)
        {
            cout << op + 2 << endl;
        }
        else
        {
            cout << op + 1 << endl;
        }
    }
    return 0;
}
