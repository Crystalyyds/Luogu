#include<iostream>
#include<stdio.h>
using namespace std;
void fun(int a,int b,int w,int k){
    while (w <= a) {
        int x,y,z;
        cin>>x>>y>>z;   
        if (b - x == y) {
            k++;
        } else if (b - x == z) {
            k++;
        } else if (b - y == z) {
            k++;
        }
        w++;
    }
    cout<<k<<endl;
}
int main(){
    int a,b;
    cin>>a>>b;
    int w=1,k=0;
    if((a>=2&&a<=100)&&(b>=2&&b<=1000)){
    fun(a,b,w,k);
    }
    return 0;
}