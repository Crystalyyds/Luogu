#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main(){
    int a,b,c;
    cin>>a>>b>>c;
    int d = c/b;
    if(d%1!=0){
        a = a-d;
    }
    a=a-d;
    cout<<a<<endl;
}