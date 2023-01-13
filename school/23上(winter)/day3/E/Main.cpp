#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
PII arr[100010];
ll n, cnt, t;
bool fun(PII x, PII y)
{
    return x.second < y.second;
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    sort(arr, arr + n, fun);
    for (int i = 0; i < n; i++)
    {

        t += arr[i].second;
        cnt += arr[i].first * t;
    }
    cout << cnt << endl;
    return 0;
}