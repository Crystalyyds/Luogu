#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, array[100], brray[100], count = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> array[i];
  }
  for (int i = 0; i < n; i++) {
    for (int o = i + 1; o < n; o++) {
      for (int p = 0; p < n; p++) {
        if (array[p] == array[i] + array[o] && brray[p] != 1) {
          count++;
          brray[p] = 1;
        }
      }
    }
  }
  cout << count;  //Êä³ö
  return 0;
}
// #include <bits/stdc++.h>
// using namespace std;
// int main() {
//   int n;
//   int array[110], brray[110];
//   cin >> n;
//   for (int i = 1; i <= n; i++) {
//     cin >> array[i];
//     brray[i] = array[i];
//   }
//   int count = 0;
//   for (int i = 1; i < n; i++) {
//     int a = array[i];
//     for (int j = i + 1; j <= n; j++) {
//       int b = array[j];
//       for (int k = 1; k <= n; k++) {
//         if (array[k] == a + b) {
//           count++;
//           brray[k] = 0;
//         }
//       }
//     }
//   }
//   cout << count << endl;
// }