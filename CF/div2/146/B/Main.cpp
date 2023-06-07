#include<bits/stdc++.h>
using namespace std;
int T;
int gcd(int a,int b){
    if(a%b==0) return b;
    else return gcd(b,a%b);
}

int main(){
    cin>>T;
    while (T--)
    {
        int a=0,b=0;
        int leg=1;
        int cnt=0;
        cin>>a>>b;
        int t = gcd(a,b);
        b = max(a,b),a = min(a,b);
        if(leg < t){
            cnt+=t-leg;
            leg = t;
        }
        if(a==leg) continue;
        else{
            cnt+=a/leg;
        }
        cnt+=b/leg;
        cout<<cnt<<endl;
    }
    return 0;
}