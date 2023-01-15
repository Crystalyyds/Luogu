#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
int qmi(int a, int k, int p)
{
    int res = 1 % p;

    while (k)
    {
        if (k & 1)
        {
            res = (LL)res * a % p;
        }
        k >>= 1;
        a = (LL)a * a % p;
    }
    return res;
}
int main()
{

    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    printf("%d\n", qmi(a, b, k));
    return 0;
}