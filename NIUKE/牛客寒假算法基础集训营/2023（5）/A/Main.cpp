#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int T = 1e5 + 10;
ll n, q, k, x, cnt;
ll arr[T], v[T];
int main()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
    }
    sort(v + 1, v + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + v[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    while (q--)
    {
        cin >> k >> x;
        ll j = 0;
        for (int i = n; i >= 1; i--)
        {
            if (x >= v[i])
            {
                j = i;
                break;
            }
        }
        //         cout<<j<<endl;

        cout << arr[j] - arr[j - k] << endl;
    }
}