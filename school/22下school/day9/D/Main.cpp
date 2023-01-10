#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
bool is_prime[100000010];
ll num[1000010];
ll cur = 1;
ll n;
vector<ll> arr;
void fun()
{
    for (ll i = 2; i <= n; i++)
    {
        if (!is_prime[i])
        {
            num[cur++] = i;
            arr.push_back(i);
        }
        for (ll j = 1; j < cur && i * num[j] <= n; j++)
        {
            is_prime[i * num[j]] = 1;
            if (!(i % num[j]))
                break;
        }
    }
}
int main()
{
    cin >> n;
    fun();
    for (ll op = arr.size() - 1; op >= 0; op--)
    {
        if (n % arr.at(op) == 0)
        {
            cout << arr.at(op);
            break;
        }
    }
    return 0;
}