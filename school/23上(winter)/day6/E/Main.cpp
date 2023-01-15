#include <bits/stdc++.h>
using namespace std;
long long n, cnt = 0;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cnt = cnt ^ temp;
    }
    if (cnt != 0)
        cout << "A";

    else
        cout << "B";
    return 0;
}
