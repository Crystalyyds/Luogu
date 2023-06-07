#include <bits/stdc++.h>
using namespace std;

int n, cnt;
string g, z, l;
bool k1, k2, k3;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> g;
        cin >> z;
        if (z == "init")
        {
            k1 = true;
            k2 = false;
            k3 = false;
        }
        if (z == "add")
        {
            k2 = true;
            cin >> l;
        }
        if (z == "rm")
        {
            k3 = true;
            cin >> l;
        }
        if (z == "commit")
        {
            if (k1)
            {
                if (k2 || k3)
                {
                    cnt += 1;
                    k2 = k3 = false;
                }
            }
        }
    }
    cout << cnt << endl;
}