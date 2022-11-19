#include <bits/stdc++.h>
using namespace std;
string a, b;
int c;
vector<int> add(vector<int> &A, vector<int> &B) {
  vector<int> C;
  int t = 0;
  for (int i = 0; i < A.size(); i++) {
    if (i < A.size()) {
      t += A[i];
    }
    if (i < B.size()) {
      t += B[i];
    }
    C.push_back(t % 10);
    t = t / 10;
  }
  if (t != 0) {
    C.push_back(t);
  }
  return C;
}
int main() {
  cin >> a >> b;
  vector<int> A, B;
  for (int i = a.size() - 1; i >= 0; i--) {
    A.push_back(a[i] - '0');
  }
  for (int i = b.size() - 1; i >= 0; i--) {
    B.push_back(b[i] - '0');
  }
  if (A.size() > B.size()) {
    auto C = add(A, B);
    for (int i = C.size() - 1; i >= 0; i--) {
      cout << C[i];
    }
  } else {
    auto C = add(B, A);
    for (int i = C.size() - 1; i >= 0; i--) {
      cout << C[i];
    }
  }
  return 0;
}