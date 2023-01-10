#include <bits/stdc++.h>
using namespace std;
int n;
string arr;
int main()
{
    cin >> n;
    cin >> arr;
    while (n--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            string ww;
            cin >> ww;
            arr = arr + ww;
            cout << arr << endl;
        }
        if (op == 2)
        {
            int a, b;
            cin >> a >> b;
            string ww;
            for (int i = a; i <= a + b; i++)
            {
                ww += arr[i];
            }
            arr = ww;
            cout << arr << endl;
        }
        if (op == 3)
        {
            int a;
            string ww, mm;
            cin >> a >> ww;
            for (int i = 0; i < arr.length(); i++)
            {
                if (i == a - 1)
                {
                    mm = mm + arr[i] + ww;
                }
                else
                {
                    mm += arr[i];
                }
            }
            arr = mm;
            cout << arr << endl;
        }
        if (op == 4)
        {
            string ww;
            cin >> ww;
            int ab = arr.find(ww);
            cout << ab << endl;
        }
    }
}