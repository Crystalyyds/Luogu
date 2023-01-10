#include <bits/stdc++.h>
using namespace std;
stack<int> arr;
int main(void)
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a;
        if (a == 1)
        {
            cin >> b;
            arr.push(b);
        }
        else
        {
            if (arr.empty())
                cout << "empty" << endl;
            else
            {
                cout << arr.top() << endl;
                arr.pop();
            }
        }
    }
    return 0;
}