#include <bits/stdc++.h>
using namespace std;
bool is_prime[100000010];
int num[1000010];
int cur = 1;
int n, p, op;
void fun()
{
    for (int i = 2; i <= n; i++)
    {
        if (!is_prime[i])
        {
            num[cur++] = i;
            op++;
        }
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
    scanf("%d", &n);
    fun();
    cout << op << endl;
}