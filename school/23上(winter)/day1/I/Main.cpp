#include <bits/stdc++.h>
using namespace std;
int n, num[1010], arr[1010];
void fun(int x)
{
    for (int i = 1; i <= x; i++)
    {
        if (i <= 10)
        {
            arr[i] = i;
        }
        else
        {
            string ww = to_string(i);
            int size = ww.size();
            int tt = pow(10, size - 1);
            if (i % tt == 0)
            {
                arr[i] = arr[i - 1] + 1;
            }
            else
            {
                arr[i] = arr[i - 1];
            }
        }
    }
}
int main()
{
    cin >> n;
    int mx = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        mx = max(mx, num[i]);
    }
    fun(mx);
    for (int i = 0; i < n; i++)
    {
        cout << arr[num[i]] << endl;
    }
    return 0;
}