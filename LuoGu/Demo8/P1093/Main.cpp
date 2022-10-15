#include <bits/stdc++.h>
using namespace std;
struct one {
  int i;
  int yw;
  int sx;
  int yy;
} arr[310];
int n;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].yw >> arr[i].sx >> arr[i].yy;
    arr[i].i = i;
  }
  for (int i = 2; i <= n; i++) {
    one temp = arr[i];
    int j;
    int tempnums = arr[i].yw + arr[i].sx + arr[i].yy;
    for (j = i - 1; j >= 1; j--) {
      if ((arr[j].yw + arr[j].sx + arr[j].yy) < tempnums) {
        arr[j + 1] = arr[j];
      } else if (tempnums = arr[j].yw + arr[j].sx + arr[j].yy) {
        if (temp.yw > arr[j].yw) {
          arr[j + 1] = arr[j];
        } else {
          break;
        }
      } else {
        break;
      }
      arr[j] = temp;
    }
  }
  for (int i = i; i <= n; i++) {
    cout << arr[i].i << " " << arr[i].yw + arr[i].sx + arr[i].yy << endl;
  }
  return 0;
}