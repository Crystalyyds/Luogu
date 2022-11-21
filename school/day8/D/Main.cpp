#include <bits/stdc++.h>
using namespace std;
typedef pair<int, vector<int>> PII;
vector<PII> arr;
int n, m;
vector<int> add(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        if (i < A.size())
        {
            t += A[i];
        }
        if (i < B.size())
        {
            t += B[i];
        }
        C.push_back(t % 10);
        t = t / 10;
    }
    if (t != 0)
    {
        C.push_back(t);
    }
    return C;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        string temp;
        cin >> temp;
        vector<int> tt;
        for (int j = temp.size() - 1; j >= 0; j--)
        {
            tt.push_back(temp[j] - '0');
        }
        arr.push_back({i, tt});
    }
    while (m--)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            long long tt[3];
            cin >> tt[1] >> tt[2] >> tt[3];
            while (tt[1] <= tt[2])
            {
                auto dang = arr.at(tt[1]);
                vector<int> ww;
                string temp = to_string(tt[3]);
                for (int j = temp.size() - 1; j >= 0; j--)
                {
                    ww.push_back(temp[j] - '0');
                }
                add(dang.second, ww);
                tt[1]++;
            }
        }
        else
        {
            int tt;
            cin >> tt;
            auto dang = arr.at(tt);
            for (int i = dang.second.size() - 1; i >= 0; i--)
            {
                cout << dang.second.at(i);
            }
            cout << endl;
        }
    }

    return 0;
}