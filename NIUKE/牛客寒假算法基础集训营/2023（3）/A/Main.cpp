#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int T = 1e5 + 10;
typedef pair<ll, ll> PII; //
map<ll, ll> m;
vector<ll> vc;
ll n, arr[T], cnt, temp;
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {

        cin >> arr[i];
        if (m[arr[i]] == 0)
            vc.push_back(arr[i]);
        m[arr[i]] += 1;
    }
    while (!vc.empty())
    {
        temp = 0;
        auto x = vc.back();
        cout << x << " ";
        if (x % 2 != 0)
        {
            cnt += x * m[x];
            vc.pop_back();
        }
        else
        {
            temp = x / 2;
            m[temp] += m[x];
            vc.pop_back();
            if (m[temp] == 0)
            {
                vc.push_back(temp);
            }
        }
    }

    // cout << cnt;
    return 0;
}