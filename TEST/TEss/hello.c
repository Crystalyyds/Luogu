#include <iostream>
#include <math.h>
using namespace std;
const double pi = 3.1415926;
double s, r, h, v;

int main()
{
    cin >> s;
    s /= pi * 4;
    r = sqrt(s);
    h = 2 * sqrt(2) * r;
    v = pi * r * r * h / 3;
    printf("%.2lf\n", v);
    printf("%.2lf\n", h);
    printf("%.2lf\n", r);
}
