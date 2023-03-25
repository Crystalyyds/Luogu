#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{

    scanf("%d", &n);
    while (n--)
    {
        int m;
        char arr[100];
        scanf("%d", &m);
        scanf("%s", arr);
        int mi = 0;
        for (int i = 0; i < m; i++)
        {
            if (arr[i] - 'a' + 1 > mi)
            {
                mi = arr[i] - 'a' + 1;
            }
        }
        cout << mi << endl;
    }
}