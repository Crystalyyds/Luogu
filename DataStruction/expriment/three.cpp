#include <bits/stdc++.h>
using namespace std;

int path[100][100];
int dist[100];
bool st[100];
int ss = 0;
typedef struct ENode
{
    int adjVex;
    int w;
    struct ENode *nextArc;
} ENode;

typedef struct
{
    int n;
    int e;
    ENode **a;
} LGraph;

int Init(LGraph *lg, int nSize)
{
    int i;
    lg->n = nSize;
    lg->e = 0;
    lg->a = (ENode **)malloc(nSize * sizeof(ENode *));
    if (!lg->a)
        return 0;
    for (i = 0; i < lg->n; i++)
        lg->a[i] = NULL;
    return 1;
}

void destory(LGraph *lg)
{
    ENode *p, *q;
    for (int i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        q = p;
        while (p)
        {
            p = p->nextArc;
            free(q);
            q = p;
        }
        free(lg->a);
        lg->n = 0;
    }
}

int Exist(LGraph *lg, int u, int v)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return 0;
    p = lg->a[u];
    while (p && p->adjVex != v)
        p = p->nextArc;
    if (!p)
        return 0;
    else
        return 1;
}

int Insert(LGraph *lg, int u, int v, int w)
{
    ENode *p;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return 0;
    if (Exist(lg, u, v))
        return 0;
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = v;
    p->w = w;
    p->nextArc = lg->a[u];
    lg->a[u] = p;
    p = (ENode *)malloc(sizeof(ENode));
    p->adjVex = u;
    p->w = w;
    p->nextArc = lg->a[v];
    lg->a[v] = p;
    lg->e++;
    path[u][v] = w;
    path[v][u] = w;
    return 1;
}
int Remove(LGraph *lg, int u, int v)
{
    ENode *p, *q = NULL;
    if (u < 0 || v < 0 || u > lg->n - 1 || v > lg->n - 1 || u == v)
        return 0;
    p = lg->a[u];
    while (p && p->adjVex != v)
    {
        q = p;
        p = p->nextArc;
    }
    if (!p)
        return 0;
    if (q)
        q->nextArc = p->nextArc;
    else
        lg->a[u] = p->nextArc;
    free(p);

    p = lg->a[v];
    while (p && p->adjVex != u)
    {
        q = p;
        p = p->nextArc;
    }
    if (!p)
        return 0;
    if (q)
        q->nextArc = p->nextArc;
    else
        lg->a[v] = p->nextArc;
    free(p);
    path[u][v] = 0x3f;
    path[v][u] = 0x3f;
    lg->e--;
    return 1;
}

void Display(LGraph *lg)
{
    int i;
    ENode *p;
    if (lg->n == 0)
    {
        printf("Пе!\n");
        return;
    }

    for (i = 0; i < lg->n; i++)
    {
        p = lg->a[i];
        if (!p)
        {
            printf("list %d is empty!\n", i);
            continue;
        }
        printf("list  %d: ", i);
        while (p)
        {
            printf("[%d:%d]", p->adjVex, p->w);
            p = p->nextArc;
        }
        printf("\n");
    }
}

int prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;

    for (int i = 0; i < ss; i++)
    {
        int t = -1;
        for (int j = 1; j <= ss; j++)
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;

        if (i && dist[t] == 0x3f)
            return 0x3f;

        if (i)
            res += dist[t];

        st[t] = true;

        for (int j = 1; j <= ss; j++)
            dist[j] = min(dist[j], path[t][j]);
    }

    return res;
}

int main()
{
    for (int i = 1; i <= ss; i++)
    {
        for (int j = 1; j <= ss; j++)
        {
            if (i == j)
                path[i][j] = 0;
            else
                path[i][j] = 0x3f;
        }
    }
    ss = 10;
    LGraph *lg;
    Init(lg, ss);
    Display(lg);
    Insert(lg, 1, 3, 5);
    Insert(lg, 1, 2, 1);
    Insert(lg, 1, 5, 6);
    Insert(lg, 2, 4, 3);
    Insert(lg, 2, 3, 5);
    Insert(lg, 3, 5, 4);
    Insert(lg, 3, 4, 6);
    Insert(lg, 3, 5, 5);
    Insert(lg, 4, 5, 2);
    Insert(lg, 5, 6, 2);
    Display(lg);
}