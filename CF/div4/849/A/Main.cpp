#include <bits/stdc++.h>
using namespace std;
bool f[26];
char temp;
int main()
{
    int n;
    cin >> n;
    string ss = "codeforces";
    for (int i = 0; i < ss.size(); i++)
    {
        f[ss[i] - 'a'] = true;
    }
    while (n--)
    {
        cin >> temp;
        if (f[temp - 'a'])
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}