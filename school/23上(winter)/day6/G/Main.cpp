#include <iostream>
using namespace std;
int main()
{
    int n, i;
    scanf("%d", &n);
    printf("%d=", n);
    for (i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            printf("%d", i);
            n = n / i;
            if (n != 1)
                printf("*");
        }
    }
    if (n != 1)
        printf("%d\n", n);
}
