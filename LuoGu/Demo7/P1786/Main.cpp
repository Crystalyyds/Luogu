#include <bits/stdc++.h>
using namespace std;
int n;
struct people {
  string name;
  string job;
  int nums;
  int grade;
} arr[120];
void fun(people array[], int lenth) {
  people temp;
  for (int i = 1; i < lenth; i++) {
    for (int j = i + 1; j > 0; j--) {
      if (array[j].nums > array[j - 1].nums) {
        temp = array[j - 1];
        array[j - 1] = array[j];
        array[j] = temp;
      } else {
        break;
      }
    }
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i].name >> arr[i].job >> arr[i].nums >> arr[i].grade;
  }
  fun(arr, n);
  for (int i = 1; i <= n; i++) {
    if (i == 1) arr[i].job = "BangZhu";
    if (i >= 2 && i <= 3) {
      arr[i].job = "FuBangZhu";
    }
    if (i >= 4 && i <= 5) arr[i].job = "HuFa";
    if (i >= 6 && i <= 9) arr[i].job = "ZhangLao";
    if (i >= 10 && i <= 16) arr[i].job = "TangZhu";
    if (i >= 17 && i <= 41) arr[i].job = "JingYing";
    if (i > 41) arr[i].job = "BangZhong";
  }
  for (int i = 1; i <= n; i++) {
    cout << arr[i].name << " " << arr[i].job << " " << arr[i].nums << " "
         << arr[i].grade << endl;
  }
}
