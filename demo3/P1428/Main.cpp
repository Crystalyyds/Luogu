#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/record/87107963
int main()
{
    int n;
    int array[10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        cin >> array[i];
        for (int j = 0; j < i; j++)
        {
            if (array[i] > array[j])
            {
                count++;
            }
        }
        cout << count <<" ";;
    }
}