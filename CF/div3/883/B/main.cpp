#include <bits/stdc++.h>
using namespace std;

int n;
char arr[5][5];
int brr[5][5];
int main()
{
    cin >> n;
    while (n--)
    {
        set<char> s;
        memset(arr, 'a', sizeof arr);
        memset(brr, 0, sizeof brr);
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
            {
                bool key = true;
                cin >> arr[i][j];
                if (arr[i][j] == '.')
                {
                    brr[i][j] = 0;
                    continue;
                }
                if (arr[i][j] == arr[i][j - 1])
                {
                    brr[i][j] = max(brr[i][j], brr[i][j - 1] + 1);
                    key = false;
                }
                if (arr[i][j] == arr[i - 1][j])
                {
                    brr[i][j] = max(brr[i][j], brr[i - 1][j] + 1);
                    key = false;
                }
                if (arr[i][j] == arr[i - 1][j - 1] && i == j)
                {
                    brr[i][j] = max(brr[i][j], brr[i - 1][j - 1] + 1);
                    key = false;
                }
                if (arr[i][j] == arr[i - 1][j + 1] && (i + j) == 4)
                {
                    brr[i][j] = max(brr[i][j], brr[i - 1][j + 1] + 1);
                    key = false;
                }
                if (key)
                {
                    brr[i][j] = 1;
                    // cout<<"ok"<<endl;
                }
            }
        // for(int i=1;i<=3;i++){
        //     for(int j=1;j<=3;j++){
        //         cout<<brr[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for (int i = 1; i <= 3; i++)
            for (int j = 1; j <= 3; j++)
            {
                if (brr[i][j] == 3)
                    s.insert(arr[i][j]);
            }
        if (s.size() == 1)
        {
            for (auto t : s)
            {
                cout << t << endl;
                break;
            }
        }
        else
            cout << "DRAW" << endl;
    }
    return 0;
}