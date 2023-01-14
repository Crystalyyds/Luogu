#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
string s1, s2;
int p[27], cnt;

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    int n;
    cin >> n;
    cin >> s1 >> s2;
    for (int i = 0; i < 27; i++)
        p[i] = i;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            int a = s1[i] - 'a', b = s2[i] - 'a';
            a = find(a), b = find(b);
            if (a != b)
            {
                p[b] = a;
                cnt++;
            }
        }
    }
    cout << cnt << endl;

    return 0;
}