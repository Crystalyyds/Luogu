#include <bits/stdc++.h>
using namespace std;
int n, arr[10000010];
int brr[10000010];
int crr[10000010];
int drr[10000010];
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    while (true)
    {
        int m = 0, num = 0, temp = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> brr[i];
            cin >> brr[i];
            if (brr[i] == 0)
                m++;
            if (m == n)
                return 0;
            for (int j = 0; j < n; j++)
            {
                if (brr[i] == arr[j] && drr[i] == 0)
                {
                    if (i == j && crr[j] == 0)
                    {
                        crr[j] = 1;
                        drr[i] = 1;
                        num++;
                    }
                    else if (i != j && crr[j] == 0)
                    {
                        temp++;
                    }
                }
            }
        }
        if (num == n)
        {
            cout << "Pass";
            return 0;
        }
        cout << num << " " << temp << endl;
    }
    // return 0;
}