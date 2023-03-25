#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int T = 1e5;
ll arr[T];
ll n, temp, a, b, c;
set<ll> st;
int main()
{
    cin >> n;
    arr[1] = 1, arr[2] = 1, arr[3] = 2;
    for (int i = 4; i <= n; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}