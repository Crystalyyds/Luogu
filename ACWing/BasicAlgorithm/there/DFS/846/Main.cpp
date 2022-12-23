#include <iostream>
#include <cstring>
using namespace std;

const int N = 100010;
bool state[N];

// ��Ϊ��˫���
int h[N], e[2 * N], ne[2 * N], idx, ans = N;
int n;
int add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}

// ���ص�����uΪ���������е������
int dfs(int u)
{
    // ���u����㱻�ѹ�
    state[u] = true;
    // size�Ǳ�ʾ��u��ȥ����ʣ�µ����������������ֵ��
    // sum��ʾ��uΪ���������ĵ�Ķ��٣���ֵΪ1����Ϊ�Ѿ�����u�����
    int size = 0, sum = 1;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (state[j])
            continue;
        // s����jΪ���ڵ�������е������
        int s = dfs(j);
        //
        size = max(size, s);
        sum += s;
    }
    // n-sum��ʾ���Ǽ���uΪ����������������ʣ�µĵ������
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