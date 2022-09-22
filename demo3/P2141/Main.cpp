#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int array[100];
    cin>>n;
    for(int i = 0; i < n; i++){
        cin>>array[i];
    }
    int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int x = array[i]-array[j];
            for(int k = 0; k < n; k++){
                if(array[k]==x){
                    count++;
                }
            }
        }
    }
    cout<<count << endl;
}