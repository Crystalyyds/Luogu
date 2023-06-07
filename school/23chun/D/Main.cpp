#include <bits/stdc++.h>
using namespace std;
double a[110], b[110];
double cnt;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        cnt += a[i] * b[i];
    }
    printf("%.4lf", cnt);
}