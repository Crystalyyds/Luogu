#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5;
int n, arr[N], op, temp, j, brr[N];
bool fun(int a, int b)
{
    return a > b;
}
int main()
{
    cin >> op;
    while (op--)
    {
        memset(brr, -1, sizeof(brr));
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for (int i = 0, j = 0; i < n; i++)
        {
            if (i % 2 == 0)
                brr[i / 2] = arr[j++];
            else
                brr[n - 1 - i / 2] = arr[j++];
        }
        memset(arr, -1, sizeof(arr));
        for (int i = 0, j = 1; j < n - 1; i++, j++)
        {
            arr[brr[i] + brr[j]] += 1;
        }
        int j = 0;
        while (arr[j] != -1)
        {
            j++;
        }
        cout << j << endl;
    }
    return 0;
}