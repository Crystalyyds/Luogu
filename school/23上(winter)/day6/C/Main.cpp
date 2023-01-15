#include <iostream>
#include <algorithm>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long LL;
int fun(LL a, LL b, LL mode)
{
    LL sum = 1;
    a = a % mode;

    while (b > 0)
    {
        if (b % 2 == 1)
            sum = (sum * a) % mode;

        b /= 2;
        a = (a * a) % mode;
    }
    return sum;
}
int main()
{

    int a, b, k;
    scanf("%d%d%d", &a, &b, &k);
    printf("%d\n", fun(a, b, k));
    return 0;
}