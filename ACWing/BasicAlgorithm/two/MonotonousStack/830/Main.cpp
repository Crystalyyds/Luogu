#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
    stack<int> aa;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int ooo;
        scanf("%d", &ooo);
        if (aa.empty())
        {
            aa.push(ooo);
            printf("%d ", -1);
            continue;
        }
        while (!aa.empty() && ooo <= aa.top())
            aa.pop();
        if (aa.empty())
        {
            printf("%d ", -1);
        }
        else
        {
            printf("%d ", aa.top());
        }
        aa.push(ooo);
    }
    return 0;
}