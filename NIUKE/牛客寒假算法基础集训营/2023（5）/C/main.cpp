#include <bits/stdc++.h>
using namespace std;
string a, b;
typedef long long ll;
ll x = 1, y = 0, z = -1, temp;
bool hhh = true;
int main()
{
    cin >> a >> b;
    if (a.size() == b.size())
    {
        for (int i = 0; i < a.size(); i++)
        {
            if (i == 0)
            {
                temp = a[i] - b[i];
            }
            else
            {
                if ((a[i] - b[i] > 0 && temp > 0) || (a[i] - b[i] < 0 && temp < 0) || (a[i] - b[i] == 0 && temp == 0))
                    continue;
                else
                {
                    hhh = false;
                    break;
                }
            }
        }
    }
    else
    {
        cout << "!";
        return 0;
    }
    if (hhh = false)
    {
        cout << "!";
        return 0;
    }
    if (temp == 0)
    {
        cout << "=";
    }
    if (temp > 0)
    {
        cout << ">";
    }
    if (temp < 0)
    {
        cout << "<";
    }
}