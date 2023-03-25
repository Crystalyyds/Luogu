#include <bits/stdc++.h>
using namespace std;
const int N = 110;
map<string, int> mp;
string arr[N], brr[5] = {"and", "not", "that", "the", "you"};
int n;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]] += 1;
    }
    for (int i = 0; i < 5; i++)
    {
        if (mp[brr[i]] >= 1)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}