// struct node ��С����
// {
//     int l, r;
//     bool operator<(const node &v) const
//     {
//         return r < v.r;
//     }
// }
// v[maxn];

// truct node ���ȶ���Ĭ��Ϊ�Ӵ�С ������Ǵ�С����
// {
//     int l, r;
//     bool operator<(const node &v) const
//     {
//         return r > v.r;
//     }
// };
// priority_queue<node> q;

// priority_queue<PII> pq1;
// priority_queue<PII, vector<PII>, less<PII>> pq1;
// �����

// priority_queue<PII, vector<PII>, greater<PII>> pq2;
// С����

#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 150010;
int h[N], e[N], ne[N], w[N], idx;
int n, m;
int dist[N];
bool ju[N];

int fun()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 1}); // first Ȩ��second ��һ����

    while (heap.size())
    {
        PII t = heap.top();
        heap.pop();
        int x = t.second, y = t.first;
        if (ju[x])
            continue;
        ju[x] = true;

        for (int i = h[x]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > y + w[i])
            {
                dist[j] = y + w[i];
                heap.push({dist[j], j});
            }
        }
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    else
        return dist[n];
}

void add(int a, int b, int c)
{
    e[idx] = b;
    w[idx] = c;
    ne[idx] = h[a];
    h[a] = idx++;
    // ˳��
}

int main()
{
    cin >> n >> m;
    memset(h, -1, sizeof(h));
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }
    cout << fun() << endl;
    return 0;
}
