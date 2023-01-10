#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e+18;
int n, arr[100];
inline int gcd(int a, int b)
{
    if (b)
        while ((a %= b) && (b %= a))
            ;
    return a + b;
}
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int m;
        scanf("%d", &m);
        int mx = 0;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
            mx = max(mx, arr[i]);
        }
        sort(arr, arr + m);
        int num = unique(arr, arr + m) - arr;
        if (num != m)
        {
            printf("NO\n");
            continue;
        }
        else
        {
            int x = 1;
            while (x <= mx)
            {
                int flag = 1;
                for (int i = 0; i < m - 1; i++)
                {
                    for (int j = i + 1; j < m; j++)
                    {
                        if (gcd(arr[i] + x, arr[j] + x) != 1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag == 0)
                        break;
                }
                if (flag == 1)
                {
                    printf("YES\n");
                    break;
                }
                x++;
            }
            if (x == mx + 1)
            {
                printf("NO\n");
            }
        }
    }
}