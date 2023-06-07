#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m, x, y, e, cnt, res; // cnt权，res所选条数
int Mark[N], p[N];

struct Node
{
    int a;
    int b;
    int ele;
} arr[N * 2];

bool fun(Node x, Node y)
{
    return x.ele < y.ele;
}

int find(int x)
{
    if (x == p[x])
        return p[x];
    else
        return p[x] = find(p[x]);
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].a >> arr[i].b >> arr[i].ele;
    }
    sort(arr, arr + m, fun);
    for (int i = 0; i < n; i++)
        p[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a1 = arr[i].a, b1 = arr[i].b, ele1 = arr[i].ele;
        if (find(a1) != find(b1))
        {
            p[find(a1)] = b1;
            res++;
            cnt += ele1;
        }
    }
    if (res < n - 1)
        cout << "impossible";
    else
        cout << cnt;
    return 0;
}