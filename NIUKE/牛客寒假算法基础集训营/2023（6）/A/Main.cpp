#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
int main()
{
    cin >> n;
    if (n >= 1 && n <= 7)
    {
        cout << "very easy";
        return 0;
    }
    if (n > 7 && n <= 233)
    {
        cout << "easy";
        return 0;
    }
    if (n > 233 && n <= 10032)
    {
        cout << "medium";
        return 0;
    }
    if (n > 10032 && n <= 114514)
    {
        cout << "hard";
        return 0;
    }
    if (n > 114514 && n <= 1919810)
    {
        cout << "very hard";
        return 0;
    }
    if (n > 1919810)
    {
        cout << "can not imagine ";
        return 0;
    }
    return 0;
}