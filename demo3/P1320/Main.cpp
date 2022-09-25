#include <bits/stdc++.h>
using namespace std;
// https://www.luogu.com.cn/record/87186710
int main() {
  string a;
  cin >> a;
  int N = a.size(), count = 0, w = 0, temp = 0;
  char arr[N][N], op = 0;
  for (int j = 0; j < N; j++) {
    arr[0][j] = a[j];
  }
  for (int i = 1; i < N; i++) {
    cin >> a;
    for (int j = 0; j < N; j++) {
      arr[i][j] = a[j];
    }
  }
  cout << N << " ";
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (arr[i][j] == '0') {
        if (op) {
          cout << count << " ";
          op = 0;
          count = 0;
        }
        count++;
      } else {
        if (!op) {
          cout << count << " ";
          count = 0;
          op = 1;
        }
        count++;
      }
    }
  }
  if (count > 0) {
    cout << count << " ";
  }

  return 0;
}

// int main() {
// string a;
// cin >> a;
// int N = a.size(), count = 0, w = 0, temp = 0;
// char arr[N][N], op = 0;
// for (int j = 0; j < N; j++) {
//   arr[0][j] = a[j];
// }
// for (int i = 1; i < N; i++) {
//   cin >> a;
//   for (int j = 0; j < N; j++) {
//     arr[i][j] = a[j];
//   }
// }

//   cout << N << " ";
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       if (arr[i][j] == op) {
//         count++;
//       } else {
//         cout << count << " ";
//         temp++;
//         count = 1;
//         op = arr[i][j];
//       }
//     }
//   }
//   temp++;
// }

// int main() {
//   int array[210 * 210], count, temp = 0, w = 0;
//   int arr[210];
//   for (int i = 0; i < 7 * 7; i++) {
//     cin >> array[i];
//     if (array[i] == temp) {
//       count++;
//     } else {
//       arr[w++] = count;
//       count = 1;
//       if (temp = 0) {
//         temp = 1;
//       } else {
//         temp = 0;
//       }
//     }
//   }
//   for (int i = 0; i < 210; i++) {
//     cout << arr[i] << " ";
//   }
// }

// int main() {
//   int N, temp = 0, count;
//   int array[210 * 210];
//   int arr[210][210];
//   for (int i = 0; i < 210 * 210; i++) {
//     cin >> array[i];
//   }
//   for (int i = 0; i < N; i++) {
//     for (int j = 0; j < N; j++) {
//       cin >> arr[i][j];
//       if (temp == arr[i][j]) {
//         count++;
//       } else {
//         temp = arr[i][j];
//         cout << count << endl;
//       }
//     }
//   }
// }