#include <bits/stdc++.h>
using namespace std;
int main()
{
    for (int i = 0; i < 5; i++)
    {
        cout << 1;
        for (int j = 0; j < 5; j++)
        {
            if (j == 3)
            {
                cout << "ok" << endl;
                break;
            }
            cout << "2";
        }
    }
}