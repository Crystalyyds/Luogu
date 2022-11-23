#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int arr[2 * 100010];
        int brr[2 * 100010];
        int m, j = 0, temp, ky = 0;
        scanf("%d", &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
            if (i == 0)
            {
                temp = arr[i];
                continue;
            }
            if (i == 1)
            {
                if (arr[i] > arr[i - 1])
                    arr[j++] = 1;
                else if (arr[i] < arr[i - 1])
                    arr[j++] = -1;
                continue;
            }
        }
    }
}