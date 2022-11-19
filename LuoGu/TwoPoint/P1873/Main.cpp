#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, m, arr[1000010], ans;
int main() {
  cin >> n >> m;
  ll mx = 0;
  for (ll i = 0; i < n; i++) {
    cin >> arr[i];
    mx = max(mx, arr[i]);
  }

  int l = 0, r = n - 1;
  while (l < mx) {
    ll cnt;
    int mid = (l + mx) >> 1;
    for (ll i = 0; i < n; i++) {
      if (arr[i] > arr[mid]) {
        cnt += arr[i] - arr[mid];
      }
    }
    if (cnt >= m) {
      ans = mid - 1;
    } else {
      ans = mid + 1;
    }
  }
  cout << ans;
  return 0;
}