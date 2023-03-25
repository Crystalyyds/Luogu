#include <bits/stdc++.h>
using namespace std;
int m;
int main()
{
    scanf("%d", &m);
    while (m--)
    {
        int arr[3];
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + 3);
        cout << arr[1] << endl;
    }
}