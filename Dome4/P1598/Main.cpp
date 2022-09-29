#include <bits/stdc++.h>
using namespace std;
string a1, a2, a3, a4;
char as[100][26];
int an[26];
int main() {
  getline(cin, a1);
  getline(cin, a2);
  getline(cin, a3);
  getline(cin, a4);
  string aa[4] = {a1, a2, a3, a4};
  for (int i = 0; i < 4; i++) {
    string temp = aa[i];
    for (int j = 0; j < temp.length(); j++) {
      if (temp[j] >= 'A' && temp[j] <= 'Z') {
        an[temp[j] - 'A'] += 1;
      }
    }
  }
  int max = an[0];
  for (int i = 1; i < 26; i++) {
    if (an[i] > max) {
      max = an[i];
    }
  }
  for (int i = 0; i < 26; i++) {
    int temp = an[i];
    for (int j = max - 1; j >= max - temp; j--) {
      as[j][i] = '*';
    }
    for (int j = 0; j <= max - temp - 1; j++) {
      as[j][i] = ' ';
    }
  }
  for (int i = 0; i < max; i++) {
    for (int j = 0; j < 26; j++) {
      cout << as[i][j];
      if (j != 25) {
        cout << " ";
      }
    }
    if (i < 25) {
      cout << endl;
    }
  }
  cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
}