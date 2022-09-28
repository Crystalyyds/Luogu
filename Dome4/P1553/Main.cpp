#include <bits/stdc++.h>
using namespace std;
void fun(string str) {
  int op = 0;
  //===================================================
  if ((int)str.find('.') != -1) {
    int temp = str.find('.');
    int op = temp;
    while (op--) {
      if (str[op] == '0') {
        temp--;
      }
      if (str[op] != '0') {
        break;
      }
    }
    for (int i = op; i >= 0; i--) {
      cout << str[i];
    }
    cout << '.';
    temp = str.find('.') + 1;
    for (int i = temp; i < str.length(); i++) {
      if (str[i] == '0') {
        temp++;
      }
      if (str[i] != '0') {
        break;
      }
    }
    for (int i = str.length(); i >= temp; i--) {
      cout << str[i];
    }
  }
  //===================================================
  if (str.find('/') != -1) {
    int temp = str.find('/');
    int op = temp;
    int count = 0;
    for (int i = 0; i < temp; i++) {
      if (str[i] == '0') {
        count++;
      }
    }
    if (count == temp) {
      cout << 0;
      temp = str.find('/') + 1;
      for (int i = temp; i < str.length(); i++) {
        if (str[i] == '0') { 
          temp++;
        }
        if (str[i] != '0') {
          break;
        }
      }
    }
    while (op--) {
      if (str[op] == '0') {
        temp--;
      }
      if (str[op] != '0') {
        break;
      }
    }
    for (int i = op; i >= 0; i--) {
      cout << str[i];
    }
    cout << '/';
    temp = str.find('/') + 1;
    for (int i = temp; i < str.length(); i++) {
      if (str[i] == '0') {
        temp++;
      }
      if (str[i] != '0') {
        break;
      }
    }
    for (int i = str.length(); i >= temp; i--) {
      cout << str[i];
    }
  }
  //===================================================
  if (str.find('%') != -1) {
    int temp = str.find('%');
    int op = temp;
    while (op--) {
      if (str[op] == '0') {
        temp--;
      }
      if (str[op] != '0') {
        break;
      }
    }
    for (int i = op; i >= 0; i--) {
      cout << str[i];
    }
    cout << '%';
  }
  if (str.find('%') == -1 && str.find('.') == -1 && str.find('/') == -1) {
    int temp = str.length();
    int num = 0;
    while (temp - 1) {
      if (str[temp - 1] == '0') {
        num++;
        temp--;
      } else {
        break;
      }
    }
    reverse(str.begin(), str.end());
    for (int i = num; i < str.length(); i++) {
      cout << str[i];
    }
  }
}
string str;
int main() {
  cin >> str;
  //   reverse(str.begin(), str.end());
  fun(str);
}