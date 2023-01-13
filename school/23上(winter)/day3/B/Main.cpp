#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> arr;
struct OO
{
    int num = 0;
    int index = 0;
    int tt = 0;
};
OO brr[100010];
bool fun(OO a, OO b)
{
    if (a.index != b.index && &a.index != 0 && b.index != 0)
    {
        return a.index < b.index;
    }
    else
    {
        return a.tt < b.tt;
    }
}
int main()
{
    int j = 1;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int temp;
        scanf("%d", &temp);
        if (arr[temp] == 0)
        {
            arr[temp] = i;
        }
        else
        {
            brr[j].num = temp;
            brr[j].index = i - arr[temp];
            brr[j].tt = arr[temp];
            arr[temp] = i;
            j++;
        }
    }
    OO temp;
    temp.index = 1e9 + 1, temp.num = 1e9 + 1, temp.tt = 1e9 + 1;
    for (int i = 1; i < j; i++)
    {
        if (brr[i].index == temp.index)
        {
            if (brr[i].tt < temp.tt)
                temp = brr[i];
        }
        else if (brr[i].index < temp.index)
            temp = brr[i];
    }
    if (temp.num == 1e9 + 1 || temp.tt == 1e9 + 1 || temp.index == 1e9 + 1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << temp.num << endl;
    }
    // sort(brr + 1, brr + j, fun);
    // if (j == 1 || brr[1].index == 0 || brr[1].tt == 0)
    //     cout << "No" << endl;
    // else
    //     cout << brr[1].num << endl;
    // return 0;
}
