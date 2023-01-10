#include <bits/stdc++.h>
using namespace std;
queue<int> arr;
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        arr.push(i);
    while (!arr.empty())
    {
        cout << arr.front() << " ";
        arr.pop();
        arr.push(arr.front());
        arr.pop();
    }
    return 0;
}