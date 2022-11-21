#include <bits/stdc++.h>
using namespace std;
int n, op = 2;
vector<long long> aa;
int brr[10];
int prime(int p)
{
    if (p <= 1)
    {
        return 0;
    }
    for (int i = 2; i <= int(sqrt(p)); i++)
    {
        if (p % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int m = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &brr[i]);
        m = max(m, brr[i]);
    }
    long long j = 1, op = 1, temp = 0;
    while (op <= m)
    {

        if (prime(op) == 1)
        {
            temp += op;
        }
        aa.push_back(temp);
        op++;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << aa.at(brr[i] - 1) << endl;
    }
    return 0;
}