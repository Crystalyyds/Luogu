#include <bits/stdc++.h>
using namespace std;
int n, cnt, num;
int main()
{
    scanf("%d", &n);
    int a = 0, b = 0;
    while (n--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (x != a || y != b)
        {
            a = x, b = y;
            num = 1;
        }
        else
        {
            num++;
        }
        cnt = max(num, cnt);
    }
    printf("%d", cnt);
    return 0;
}