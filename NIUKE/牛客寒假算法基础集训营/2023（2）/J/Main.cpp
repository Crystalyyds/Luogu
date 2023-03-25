#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
typedef pair<int, int> PII;
ll T, n, x, y;
int main()
{
    cin >> T;
    while (T--)
    {
        ll arr[N], brr[N], cnt = 0, w = 0, temp = 0, op = 0;
        map<int, int> mp;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            mp[abs(arr[i])] += 1;
        }
        sort(arr, arr + n);
        for (auto [key1, num1] : mp)
        {
            for (auto [key2, num2] : mp)
            {
                if (key1 == key2)
                {
                    cnt += (key1 + key2) * (num1 * num1);
                }
                else
                {
                    cnt += (key1 + key2) * (num1 * num2 * 2);
                }
            }
        }
        // for (int i = 0; i < n; i++)
        // {
        //     for (int j = i; j < n; j++)
        //     {
        //         if (arr[i] == arr[j])
        //             cnt += arr[i] + arr[j];
        //         else
        //             cnt += (arr[i] + arr[j]) * 2;
        //     }
        // }
        cout << cnt << endl;
    }
}
