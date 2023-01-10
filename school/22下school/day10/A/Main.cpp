#include <iostream>
using namespace std;
int n, m, arr[1010];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        arr[i] = arr[i - 1] + temp;
    }
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        printf("%d\n", arr[y] - arr[x - 1]);
    }
    return 0;
}