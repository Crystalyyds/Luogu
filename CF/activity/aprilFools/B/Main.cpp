#include <bits/stdc++.h>
using namespace std;
string n;
int main()
{
    cin >> n;
    if (n.size() == 1)
    {
        cout << "YES";
        return 0;
    }
    else if (n[0] == n[1])
    {
        cout << "YES";
        return 0;
    }
    else
    {
        cout << "NO";
    }
    return 0;
}