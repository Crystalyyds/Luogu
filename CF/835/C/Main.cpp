#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int m, ky = 0;
        scanf("%d", &m);
        int mx1 = 0, mx2 = 0, arr[2 * 100010], j;
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
            if (max(arr[i], mx1) != mx1)
            {
                mx2 = mx1;
                mx1 = max(arr[i], mx1);
                j = i;
            }
            else
            {
                mx2 = max(arr[i], mx2);
            }
            if (i != 0)
            {
                if (arr[i] != arr[i - 1])
                    ky = 1;
            }
        }
        if (ky == 0)
        {
            for (int i = 0; i < m; i++)
                printf("%d ", 0);
            continue;
        }
        for (int i = 0; i < m; i++)
        {
            if (i == j)
            {
                printf("%d ", arr[i] - mx2);
            }
            else
            {
                printf("%d ", arr[i] - arr[j]);
            }
        }
        printf("\n");
    }
    return 0;
}