#include <bits/stdc++.h>
using namespace std;
int n, m, op, y = 2;
double x = 2, num = 0;
double arr[10010];
bool fun(double x, double y)
{
    return x > y;
}
void fun1(double arr[])
{
    while (true)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] / y > 0)
            {
                cnt += arr[i] / y;
            }
            if (cnt >= m)
            {
                num = arr[i] / x;
                return;
            }
        }
        x += 1;
        y++;
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, fun);
    fun1(arr);
    string ss = to_string(num);
    cout << num << endl;
    for (int i = 0; i < ss.length(); i++)
    {
        if (ss[i] == '.')
        {
            op = i;
            if (ss[i + 3] >= 5)
            {
                ss[i + 2] += 1;
                break;
            }
        }
    }
    for (int i = 0; i <= op + 2; i++)
    {
        cout << ss[i];
    }

    return 0;
}