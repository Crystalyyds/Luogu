#include <bits/stdc++.h>
using namespace std;
//https://www.luogu.com.cn/record/87108922
int main(){
    int y;
    int array[101];
    for (int i = 0; i < 101; i++) {
        cin >> array[i];
        if (array[i] == 0){
            y = i;
            break;
        }
    }
    for (int i = y-1; i >= 0; i--) {
        cout << array[i]<< " ";
    }

}