#include <bits/stdc++.h>
using namespace std;
const int N = 5 * 1000010;
int n, m, arr[N], brr[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        brr[i] = arr[i] - arr[i - 1];
    }
    for (int i = 0; i < m; i++)
    {
        int l, r, p;
        scanf("%d%d%d", &l, &r, &p);
        brr[l] += p;
        brr[r + 1] -= p;
    }
    for (int i = 1; i <= n; i++)
    {
        arr[i] = arr[i - 1] + brr[i];
    }
    sort(arr + 1, arr + 1 + n);
    printf("%d", arr[1]);
    return 0;
}