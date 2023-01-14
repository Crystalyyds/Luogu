#include <bits/stdc++.h>
using namespace std;
string arr;
stack<char> stk;
int n, k;
int main()
{
    cin >> n;
    cin >> arr;
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        char temp = arr[i];
        while (!stk.empty() && stk.top() >= temp && k > 0)
        {
            stk.pop();
            k--;
            if (temp == '0' && stk.empty())
                continue;
        }
        stk.push(temp);
    }
    while (k > 0)
    {
        stk.pop();
        k--;
    }
    string cnt;
    while (!stk.empty())
    {
        cnt += stk.top();
        stk.pop();
    }
    for (int i = cnt.length() - 1; i >= 0; i--)
    {
        cout << cnt[i];
    }
    return 0;
}