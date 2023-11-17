#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
struct node
{
    int a, b, c, d;
    int na, nb, nc, nd;
    int a1, b1, c1, d1;
    int k;
    bool operator<(const node &v) const
    {
        return k < v.k;
    }
} arr[N];

int st[N], brr[N];
int n;
int ya, yb, yc, yd;
bool kk = 0;
void fun(int u)
{
    if (u > n)
    {
        kk = 1;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        // cout << i << endl;
        if (!st[i] && arr[i].na - arr[i].a <= ya && arr[i].nb - arr[i].b <= yb && arr[i].nc - arr[i].c <= yc && arr[i].nd - arr[i].d <= yd)
        {
            st[i] = 1;
            brr[u] = i;
            arr[i].k = u;
            ya += arr[i].a, yb += arr[i].b, yc += arr[i].c, yd += arr[i].d;
            // cout << ya << " " << yb << " " << yc << " " << yd << endl;
            fun(u + 1);
            if (kk == 1)
                return;
            // st[u] = 0;
        }
    }
}

int main()
{
    cin >> n;
    cin >> ya >> yb >> yc >> yd;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].c >> arr[i].d;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].na >> arr[i].nb >> arr[i].nc >> arr[i].nd;
        arr[i].k = arr[i].na - arr[i].a + arr[i].nb - arr[i].b + arr[i].nc - arr[i].c + arr[i].nd - arr[i].d;
        // heap.push(arr[i]);
    }
    fun(1);
    if (kk = true)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i].k << " ";
        }
    }
    else
    {
        cout << "NO" << endl;
    }
}