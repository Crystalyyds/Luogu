#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin >> n;
    if (n % 2 == 1)
    {
        cout << "Yaya-win!";
    }
    else if (n % 2 == 0)
    {
        cout << "win-win!";
    }
    else
    {
        cout << "Sajin-win!";
    }
    return 0;
}
