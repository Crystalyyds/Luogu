#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define pi 3.1415926
int main(){
    int r,h;
    cin>>h>>r;
    double c = pi*r*h*r/1000;
    int i=1;
    while (1)
    {
        if(i*c>=24){
            cout<<i<<endl;
            break;
        }
        i++;
    }
    
}