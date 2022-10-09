#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x=c-a,y=d-b;
    if(y<0){
        x--;
        y+=60;
    }
    cout<<x<<" "<<y<<endl;
}