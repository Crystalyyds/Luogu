#include <iostream>
using namespace std;
typedef long long ll;
ll n, ans;
int main()
{
    cin >> n;
    while (n > 2)
    {
        n = n / 2 + 1;
        ans++;
    }
    cout << ans;
}
