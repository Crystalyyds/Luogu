#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n, arr[N], cnt;
bool st[N];
int fun()
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            arr[cnt++] = i;
        for (int j = 0; arr[j] <= n / i; j++)
        {
            st[arr[j] * i] = true;
            if (i % arr[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    cin >> n;
    cout << fun();
    return 0;
}
