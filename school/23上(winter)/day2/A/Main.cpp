#include <bits/stdc++.h>
using namespace std;
int n, m;
int main()
{
    vector<int> arr;
    cin >> n >> m;
    int temp;
    int x, y;
    char op;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        arr.push_back(temp);
    }
    for (int i = 0; i < m; i++)
    {

        cin >> op;
        if (op == 'D')
        {
            cin >> x;
            if (x > arr.size())
                continue;
            arr.erase(arr.begin() + x);
        }
        else
        {
            cin >> x >> y;
            if (x > arr.size())
                arr.push_back(y);
            else
                arr.insert(arr.begin() + x, y);
        }
    }
    cout << arr.size() << endl;
    for (vector<int>::iterator it = arr.begin(); it != arr.end(); it++)
        cout << *it << ' ';

    return 0;
}