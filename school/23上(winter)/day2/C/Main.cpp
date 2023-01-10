#include <bits/stdc++.h>
using namespace std;
map<int, int> arr, brr;
int n;
int main()
{
    cin >> n;
    while (n--)
    {
        int op = 1;
        int x, y;
        cin >> x >> y;
        int a = x, b = y;

        while (x--)
        {
            int temp;
            cin >> temp;
            arr[temp] += 1;
        }
        while (y--)
        {
            int temp;
            cin >> temp;
            brr[temp] += 1;
        }

        for (auto [key, val] : brr)
        {
            if (val <= arr[key])
            {
                continue;
            }
            else
            {
                op = 0;
                cout << "No" << endl;
                break;
            }
        }
        if (op == 1)
        {
            cout << "Yes" << endl;
        }
        arr.clear(), brr.clear();
    }
    return 0;
}