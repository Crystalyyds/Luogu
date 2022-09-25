#include <bits/stdc++.h>
#include <math.h>
using namespace std;
int main() {
  int num, temp = 0;
  int arr[100];
  int N, W;
  cin >> N >> W;
  int array[210][210];
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (num == W) {
        num = 0;
        cin >> W;
        if (temp == 1) {
          temp = 0;
        } else {
          temp = 1;
        }
      }
      array[i][j] = temp;
      num++;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cout << array[i][j];
    }
    cout << endl;
  }
}

// int main(){
//     int N,temp=0,count;
//     cin>>N;
//     int arr[N][N];
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             cin >> arr[i][j];
//             if(temp==arr[i][j]){
//                 count++;
//             }else {
//                 temp =arr[i][j];
//                 cout<<count << endl;
//             }
//         }
//     }
// }