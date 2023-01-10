#include <bits/stdc++.h>
using namespace std;
bool is_prime[100000010];
int num[1000010];
int cur = 1;
int n, p;
void fun()
{
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
            num[cur++] = i;
        for (int j = 1; j < cur && i * num[j] <= n; j++)
        {
            is_prime[i * num[j]] = 1;
            if (!(i % num[j]))
                break;
        }
    }
}
int main()
{
    scanf("%d%d", &n, &p);
    fun();
    for (int i = 0; i < p; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%d\n", num[x]);
    }
    return 0;
}
