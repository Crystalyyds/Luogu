#include <bits/stdc++.h>
using namespace std;
string arr;
int main()
{
    arr = "IDA$Atc~}Rjwtufc}$T$Kg$83%";
    for (int i = 0; i < arr.length(); i++)
    {
        if (arr[i] >= 'a' && arr[i] <= 'z')
        {
            arr[i] = arr[i] - 2;
        }
        else if (arr[i] >= 'A' && arr[i] <= 'Z')
        {
            arr[i] = arr[i] + 2;
        }
        else if (arr[i] >= '0' && arr[i] <= '9')
        {
            arr[i] = arr[i] - 3;
        }
        else
        {
            arr[i] = arr[i] - 4;
        }
        cout << arr[i];
    }
    return 0;
}