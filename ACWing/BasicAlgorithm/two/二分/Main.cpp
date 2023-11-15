#include <bits/stdc++.h>
using namespace std;
int arr[100];
int n, m;
int fun(int a, int b, int k)
{
    int l = a, r = b;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (arr[mid] < k)
            l = mid + 1;
        else
            r = mid;
    }
    return l;
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    while (m--)
    {
        int k;
        cin >> k;
        int op = fun(1, n, k);
        cout << op << endl;
    }
}