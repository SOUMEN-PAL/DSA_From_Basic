#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    ll maxNumber = LONG_LONG_MIN;
    ll minNumber = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      maxNumber = max(maxNumber, a[i]);
      minNumber = min(minNumber , a[i]);
    }
    

    cout << maxNumber - minNumber << endl;
  }

  return 0;
}
