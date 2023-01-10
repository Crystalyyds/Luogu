#include <bits/stdc++.h>
using namespace std;
int n, op = 2;
int arr[104743];
int brr[110];
int prime(int p)
{
    if (p <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= int(sqrt(p)); i++)
    {
        if (p % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int m = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &brr[i]);
        m = max(m, brr[i]);
    }
    int j = 1, op = 2;
    while (j <= m)
    {
        if (prime(op) == 1)
        {
            arr[j] = op;
            j++;
        }
        op++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[brr[i]] << endl;
    }
    return 0;
}