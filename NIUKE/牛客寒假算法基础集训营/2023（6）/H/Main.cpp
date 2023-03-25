#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
double cnt;
double n, l, r;
int main()
{
    cin >> n;
    cin >> l >> r;
    if (n > r)
    {
        cout << 1;
        return 0;
    }
    if (n == r)
    {
        cout << 0;
        return 0;
    }
    cnt = (n - l) / (r - l + 1);
    printf("%0.12f", cnt);
    return 0;
}