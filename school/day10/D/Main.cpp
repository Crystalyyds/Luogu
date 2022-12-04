#include <iostream>
using namespace std;
int a, b, p;
int quickmi(int a, int b, int p)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (long long)res * a % p;
        b >>= 1;
        a = (long long)a * a % p;
    }
    return res;
}
int main()
{
    cin >> a >> b >> p;
    int an = quickmi(a, b, p);
    cout << a << "^" << b << " mod " << p << "=" << an;
    return 0;
}
