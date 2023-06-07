#include <bits/stdc++.h>
using namespace std;
int n;
int a[6] = {3, 1, 2, 2, 3, 3};
int cnt;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cnt += a[i % 6];
    }
    cout << cnt;
}