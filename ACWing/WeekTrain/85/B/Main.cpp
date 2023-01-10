#include <bits/stdc++.h>
using namespace std;
long long n, w[26], cnt;
char arr[1010];
int main()
{
    scanf("%s", arr);
    scanf("%d", &n);
    int mx = 0, index = -1;
    for (int i = 0; i < 26; i++)
    {
        scanf("%d", &w[i]);
        if (w[i] > mx)
        {
            mx = w[i];
            index = i;
        }
    }
    int size = strlen(arr);
    for (int i = 0; i < size; i++)
    {
        cnt += w[arr[i] - 'a'] * (i + 1);
    }
    for (int i = size; i < size + n; i++)
    {
        cnt += (i + 1) * mx;
    }
    printf("%d", cnt);
    return 0;
}