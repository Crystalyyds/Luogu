#include <bits/stdc++.h>
using namespace std;
const int T = 1e4 + 10;
int n, temp, arr[26], brr[4], cnt;
string str;
string s = "MEOW";
set<char> ss;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> temp;
        cin >> str;
        memset(brr, 0, sizeof(brr));
        int j = 0, cnt = 0;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] <= 'z' && str[i] >= 'a')
                str[i] = str[i] - 32;
            ss.insert(str[i]);
        }
        if (ss.size() != 4)
        {
            cout << "NO" << endl;
            continue;
        }
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == s[j % 4])
            {
                j++;
                cnt++;
                brr[j % 4] = 1;
            }
        }
        if (cnt == 4)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
        ss.clear();
    }
    return 0;
}