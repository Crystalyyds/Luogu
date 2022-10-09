#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    double a,b,c=1.9;
    int i=1;
    cin>>a>>b;
    while(1){
        if(c*i>a+b/10){
            cout<<i-1<<endl;
            break;
        }
        i++;
    }
}