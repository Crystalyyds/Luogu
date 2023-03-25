#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int fa[N], za[N];
int a[N];
int n, k;
int sum;
int main()
{
    int f = 0, z = 0;
    scanf("%d%d", &n, &k);
    while (n--)
    {
        int x;
        cin >> x;
        if (x < 0)
            fa[f++] = x;
        else
            za[z++] = x;
    }
    sort(fa, fa + f);
    sort(za, za + z);
    int ai = 0;
    int j;
    if (f % 2 != 0)
        f--;
    if (z % 2 != 0)
        j = 1;
    for (int i = 0; i < f; i += 2)
    {
        a[ai] = fa[i] * fa[i + 1];
        ai++;
    }

    for (int i = j; i < z; i += 2)
    {
        a[ai] = za[i] * za[i + 1];
        ai++;
    }
    sort(a, a + ai);
    reverse(a, a + ai);
    for (int i = 0; i < k; i++)
        sum += a[i];
    cout << sum << endl;
    return 0;
}
