#include <iostream>
using namespace std;
#define N 1000010
int arr[N];
void f(int n)
{
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++)
    {
        arr[i] = (2 * arr[i - 1] + arr[i - 2]) % 32767;
    }
}
int main()
{
    int n;
    int a;
    cin >> n;
    f(N);
    for (int i = 1; i <= n; i++)
    {
        cin >> a;
        cout << arr[a] << endl;
    }
    return 0;
}