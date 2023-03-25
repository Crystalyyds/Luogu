#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll brr[6] = {1, 2, 3, 5, 10, 20}, cnt, arr[6];
bool judge[1010];
int main()
{
    judge[0] = true;
    for (int i = 0; i < 6; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < 6; i++)
    {
        for (int j = 1; j <= brr[i]; j++)
        {
            for (int z = 1000; z >= arr[i]; z--)
            {
                judge[z] = judge[z - arr[i]];
            }
        }
    }
    for (int i = 1; i <= 1000; i++)
    {
        if (judge[i])
            cnt++;
    }

    cout << "Total=" << cnt;
    return 0;
}