#include <bits/stdc++.h>
using namespace std;
int arr[1000000000];
int main()
{
    int op;
    scanf("%d", &op);
    while (op--)
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int temp;
            scanf("%d", &temp);
            arr[i] = temp;
        }
        sort(arr + 1, arr + 1 + n);
        int j = 1, z = 1;
        for (int i = 1; i <= m; i++)
        {
            int temp;
            scanf("%d", &temp);
            if (temp > arr[j])
            {
                arr[j] = temp;
                j++;
            }
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += arr[i];
        }
        printf("%d", cnt);
        return 0;
    }
}