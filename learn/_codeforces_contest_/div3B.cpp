#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

bool helper(ll n) {
  ll x = (ll)floor(sqrt(n));
  return x * x == n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    if (n == 1 || helper(sum)) {
      cout << -1 << "\n";
      continue;
    }
    vector<ll> arr(n);
    arr[0] = 2;
    arr[1] = 1;
    for (ll i = 2; i < n; i++) {
      arr[i] = i + 1;
    }
    ll res = 0;
    for (ll i = 0; i < n; i++) {
      res += arr[i];
      while (i < n - 1 && helper(res)) {
        ll temp1 = arr[i], temp2 = arr[i + 1];
        swap(arr[i], arr[i + 1]);
        res = res - temp1 + temp2;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
