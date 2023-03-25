#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1e5 + 10;
int arr[N];
int n;
map<int, int> mp;
int cnt;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    for (auto [key, value] : mp)
    {
        cnt += value / 2;
    }
    cout << cnt;
    return 0;
}