#include <bits/stdc++.h>
using namespace std;
int n, cnt, i;
int main()
{
    cin >> n;
    // cout << (int)sqrt(n) << endl;
    for (i = (int)sqrt(n); i * i <= n;)
    {
        i++;
    }
    cout << i << endl;

    return 0;
}