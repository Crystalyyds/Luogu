#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5;
const int M = 1e5;
int n, m, t;
struct One
{
    int id;
    string name;
    int *b;
    int nn;
    int time;
} arr[N];
bool fun(int x, int y)
{
    return x < y;
}

bool fun1(One x, One y)
{
    if (x.nn == y.nn)
    {
        return x.time < y.time;
    }
    else
    {
        return x.nn > y.nn;
    }
}

int main()
{
    cin >> n >> m >> t;
    for (int i = 0; i < n; i++)
    {
        arr[i].b = (int *)malloc(sizeof(int) * m);
        int res = 0;
        cin >> arr[i].id >> arr[i].name;
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i].b[j];
        }
        sort(arr[i].b, arr[i].b + m, fun);
        for (int j = 0; j < m; j++)
        {
            if (arr[i].b[j] == -1)
                continue;
            res += arr[i].b[j];
            if (res < t)
            {
                arr[i].nn += 1;
                // cout << arr[i].b[j] << " ";
                arr[i].time = arr[i].time + res;
            }
            else
            {
                break;
            }
            // cout << arr[i].b[j] << " ";
        }
        // cout << endl;
    }
    sort(arr, arr + n, fun1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i].id << " " << arr[i].name << endl;
    }
    return 0;
}