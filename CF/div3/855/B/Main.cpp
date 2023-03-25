#include <bits/stdc++.h>
using namespace std;
int n, x, y, cnt, temp;
string str;
int arr[26], brr[26];
int main()
{
    cin >> n;
    while (n--)
    {
        memset(arr, 0, sizeof(arr));
        memset(brr, 0, sizeof(brr));
        cnt = 0;
        cin >> x >> y;
        cin >> str;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] >= 'a' && str[i] <= 'z')
                arr[str[i] - 'a'] += 1;
            else
                brr[str[i] - 'A'] += 1;
        }
        for (int i = 0; i < str.size(); i++)
        {
            cnt += min(arr[i], brr[i]);
        }
        for (int i = 0; i < 26 && y; i++)
        {
            temp = abs(arr[i] - brr[i]);
            while (y && temp > 1)
            {
                temp -= 2;
                y--;
                cnt++;
            }
        }
        cout << cnt << endl;
    }
}