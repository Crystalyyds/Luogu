#include <stdio.h>
int main()
{
    int *arr;
    arr = (int *)malloc(3 * 3 * 3 * sizeof(int));
    *(arr + 3 * 1 * 1 + 3 * 1 + 1) = 23;
    printf("%d", (arr + 3 * 1 * 1 + 3 * 1 + 1));
}