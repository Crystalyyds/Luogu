#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
PII arr[1010];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int op, x, y;
        scanf("%d%d%d", &op, &x, &y);
        arr[op].first += x;
        arr[op].second += y;
    }
    for (int i = 1; i <= 2; i++)
    {
        if (arr[i].first >= arr[i].second)
        {
            printf("LIVE\n");
        }
        else
        {
            printf("DEAD\n");
        }
    }

    return 0;
}
