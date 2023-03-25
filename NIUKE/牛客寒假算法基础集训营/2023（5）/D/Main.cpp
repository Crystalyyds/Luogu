#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
const int T1 = 1e5 + 10;
const int T2 = 1e9 + 10;
PII arr[T1], brr[T1];
bool a = true, b = true;
ll n, w1, w2, a1, a2, cnt1, cnt2;
int main()
{
    cin >> n;
    arr[0].first = 1;
    arr[0].second = 1;
    brr[0].first = 1;
    brr[0].second = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> brr[i].first >> brr[i].second;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr[i].first > arr[i - 1].second + 1)
            a = false;
        if (brr[i].first > brr[i - 1].second + 1)
            b = false;
        if (a)
            cnt1 = arr[i].second;
        if (b)
            cnt2 = brr[i].second;
        //         cout<<cnt1<<"    "<<cnt2<<endl;
        if (cnt1 - cnt2 == 0)
        {
            cout << "win_win!" << endl;
            cout << 0 << endl;
        }
        else if (cnt1 - cnt2 > 0)
        {
            cout << "sa_win!" << endl;
            cout << cnt1 - cnt2 << endl;
        }
        else
        {
            cout << "ya_win!" << endl;
            cout << cnt2 - cnt1 << endl;
        }
    }
    return 0;
}