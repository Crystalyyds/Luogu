#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> x, y, z;
int main()
{
    cin >> n >> m;
    int x1 = n, y1 = m;
    while (n--)
    {
        int temp;
        cin >> temp;
        x.insert(temp);
    }
    while (m--)
    {
        int temp;
        cin >> temp;
        y.insert(temp);
    }
    if (x1 > y1)
    {
        for (auto it = y.begin(); it != y.end(); it++)
        {
            x.insert(*it);
        }
        for (auto it = x.begin(); it != x.end(); it++)
        {
            cout << *it << " ";
        }
    }
    else
    {
        for (auto it = x.begin(); it != x.end(); it++)
        {
            y.insert(*it);
        }
        for (auto it = y.begin(); it != y.end(); it++)
        {
            cout << *it << " ";
        }
    }
    return 0;
}