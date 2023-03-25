#include <bits/stdc++.h>
using namespace std;
int n, temp;
char op;
string ss;
typedef pair<int, int> PII;
PII arr;
map<char, int> mp;
int main()
{
    cin >> n;
    mp['U'] = 1;
    mp['D'] = -1;
    mp['L'] = -1;
    mp['R'] = 1;
    while (n--)
    {
        bool hhh = true;
        cin >> temp;
        cin >> ss;
        arr.first = arr.second = 0;
        for (int i = 0; i < temp; i++)
        {
            op = ss[i];
            if (op == 'U' || op == 'D')
            {
                arr.second += mp[op];
            }
            else
            {
                arr.first += mp[op];
            }
            if (arr.first == arr.second && arr.second == 1)
            {
                cout << "YES" << endl;
                hhh = false;
                break;
            }
        }
        if (hhh)
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}