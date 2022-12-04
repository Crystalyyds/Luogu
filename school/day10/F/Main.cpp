#include <bits/stdc++.h>
using namespace std;
int n;
struct person
{
    string name;
    int y, m, d;
    int index;
} arr[110];
bool fun(person a, person b)
{
    if (a.y != b.y)
    {
        return a.y < b.y;
    }
    else
    {
        if (a.m != b.m)
        {
            return a.m < b.m;
        }
        else
        {
            if (a.d != b.d)
            {
                return a.d < b.d;
            }
            else
            {
                return a.index > b.index;
            }
        }
    }
}
int main()
{
    std::ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].name >> arr[i].y >> arr[i].m >> arr[i].d;
        arr[i].index = i;
    }
    sort(arr + 1, arr + 1 + n, fun);
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i].name << endl;
    }
    return 0;
}