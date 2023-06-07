#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e4 + 10;
int n, m, k;
struct Edge
{
    int a, b, w;
} edge[M];

int dist[N], Last[N];

void fun()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    for (int i = 0; i < k; i++)
    {
        memcpy(Last, dist, sizeof dist);
        for (int j = 0; j < m; j++)
        {
            int a = edge[j].a, b = edge[j].b, w = edge[j].w;
            dist[b] = min(dist[b], Last[a] + w);
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }
    fun();
    if (dist[n] > 0x3f3f3f / 2)
        cout << "impossible" << endl;
    else
        cout << dist[n] << endl;
    return 0;
}
