#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
bool state[N];

// 因为是双向边
int h[N], e[2 * N], ne[2 * N], idx, ans = N;
int n;
int add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// 返回的是以u为根的子树中点的数量
int dfs(int u)
{
    // 标记u这个点被搜过
    state[u] = true;
    // size是表示将u点去除后，剩下的子树中数量的最大值；
    // sum表示以u为根的子树的点的多少，初值为1，因为已经有了u这个点
    int size = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (state[j])
            continue;
        // s是以j为根节点的子树中点的数量
        int s = dfs(j);
        //
        size = max(size, s);
        sum += s;
    }
    // n-sum表示的是减掉u为根的子树，整个树剩下的点的数量
    size = max(size, n - sum);
    ans = min(size, ans);
    return sum;
}

int main()
{
    cin >> n;
    memset(h, -1, sizeof h);
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        add(a, b);
        add(b, a);
    }
    dfs(1);
    cout << ans;
    return 0;
}