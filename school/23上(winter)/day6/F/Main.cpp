#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, a, b;
ll gcd(ll a, ll b)
{
    if (a % b == 0)
        return b;
    else
        return (gcd(b, a % b));
}
ll lcm(ll a, ll b)
{
    return a * b / gcd(a, b);
}
int main()
{
    cin >> n >> m;
    a = gcd(n, m);
    b = lcm(n, m);
    cout << a << "    " << b;
}