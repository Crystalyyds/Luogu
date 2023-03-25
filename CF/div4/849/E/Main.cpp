#include <bits/stdc++.h>
using namespace std;
const int T = 2 * 1e5;
int n, temp, arr[T];
long long cnt;
map<int, int> mp;
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> temp;
        for (int i = 0; i < temp; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < temp; i++)
        {
            if (arr[i] < 0)
            {
                cnt += abs(arr[i]);
            }
        }
    }

    return 0;
}