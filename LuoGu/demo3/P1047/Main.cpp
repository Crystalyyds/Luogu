#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/record/87120325
int main(){
    int array[10010];
    set<int> s;
    int l,m,a,b;
    cin>>l >> m;
    for(int i=0;i<=l;i++)
    {
        array[i]=1;
    }
    for (int i = 0; i < m; i++) {
        cin>>a>>b;
        for(int j=a;j<=b; j++){
            array[j]=0;
        }
    }
    int count = 0;
    for (int i = 0; i <= l; i++) {
        if (array[i]==1){
            count++;
        }
    }
    cout << count << endl;
    return 0;
}