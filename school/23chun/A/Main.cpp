#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
ll a[N], b[N];
typedef pair<int, int> PII;
map<PII, int> m;
int n;

int fun(int l, int r)
{
    if (m[{l, r}] == 0)
    {
        m[{l, r}] = max(fun(l, r - 1), a[r]);
    }else{
        return 
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
}