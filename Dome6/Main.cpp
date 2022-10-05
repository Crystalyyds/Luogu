#include <bits/stdc++.h>
using namespace std;
string a, b, arr;
int main() {
  cin >> a >> b;
  if (b.size() > a.size()) {
    string temp = a;
    a = b;
    b = temp;
  }
  int i = b.size();
  while (i) {
    i--;
    int wp = i;
    int inta = (int)a[i];
    int intb = (int)b[i];
    if (inta + intb >= 10) {
      a[i] = (inta + intb) % 10;
      a[wp - 1] = a[wp - 1] + (inta + intb) / 10;
    } else {
      a[i] = (inta + intb);
    }
  }
  cout << a << endl;
}