#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
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
