#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m;
int q[N];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d\n", &q[i]);
    scanf("%d", &m);
    while (m--)
    {
        int x;
        scanf("%d", &x);

        int l = 0, r = n - 1;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (q[mid] >= x)
                r = mid;
            else
                l = mid + 1;
        }

        if (q[l] != x)
            cout << "NO" << endl;
        else
        {
            int l = 0, r = n - 1;
            while (l < r)
            {
                int mid = l + r + 1 >> 1;
                if (q[mid] <= x)
                    l = mid;
                else
                    r = mid - 1;
            }
            cout << "Yes" << endl;
        }
    }
    return 0;
}
