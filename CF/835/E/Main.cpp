#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    scanf("%d", &n);
    while (n--)
    {
        int m, ka, j = 0, z = 0;
        scanf("%d", &m);
        int arr[2 * 100010];
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0 && ka == 0)
            {
                j = i;
                ka = 1;
            }
            if (arr[i] == 1)
            {
                z = i;
            }
        }
        int index = m - 1, ky = 0, ww;
        int temp = 0;
        if (j == 0)
        {
            arr[0] = 1;
            for (int i = m - 2; i >= 0; i--)
            {
                if (arr[i] > arr[i + 1])
                {
                    temp = temp + temp + 1;
                }
                else if (arr[i] == arr[i + 1])
                {
                    temp += temp;
                }
            }
            printf("%d\n", temp);
            continue;
        }
        else
        {
            arr[z] = 0;
            for (int i = m - 2; i >= 0; i--)
            {
                if (arr[i] > arr[i + 1])
                {
                    temp = temp + temp + 1;
                }
                else if (arr[i] == arr[i + 1])
                {
                    temp += temp;
                }
            }
            printf("%d\n", temp);
        }
    }
}