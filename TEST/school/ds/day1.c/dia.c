#include <stdio.h>
long long n;
long long fun(long long n)
{
    if (n == 0 || n == 1)
        return 1;
    else if (n > 0)
        return n * fun(n - 1);
    else if (n < 0)
        return 0;
}
int main()
{
    scanf("%d", &n); // ÊäÈën;
    printf("%d", fun(n));
}