#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, m;
int arr[N], brr[N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        brr[i] = arr[i] - arr[i - 1];
    }
    for (int i = 1; i <= m; i++)
    {
        int l, r, k;
        cin >> l >> r >> k;
        brr[l] += k;
        brr[r + 1] -= k;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = brr[i] + arr[i - 1];
        cout << arr[i] << " ";
    }
}
