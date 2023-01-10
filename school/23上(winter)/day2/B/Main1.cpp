#include <bits/stdc++.h>
using namespace std;
int n, m;
set<int> arr;
int main()
{
    int x;

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        arr.insert(x);
    }

    for (int i = 0; i < m; i++)
    {
        cin >> x;
        arr.insert(x);
    }

    int cnt = 0;
    for (auto it = arr.begin(); it != arr.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    arr.clear();

    return 0;
}
