#include <iostream>
using namespace std;
const int N = 100010;
int dp[N][3], t, n, a[N];
int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = dp[i - 1][0] + a[i];
        }
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    return 0;
}
