#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    ll n, x, k;
    cin >> n >> x >> k;
    string s;
    cin >> s;
    ll resets = 0;
    ll time = 0;
    ll rob_position = x;
    bool reachedZero = false;
    for (int i = 0; time < k && i < n; i++) {
      time++;
      if (s[i] == 'L') {
        rob_position--;
      } else {
        rob_position++;
      }
      if (rob_position == 0) {
        resets++;
        reachedZero = true;
        break;
      }
    }
    if (time >= k || !reachedZero) {
      cout << resets << "\n";
      continue;
    }

    ll cycle_time = 0;
    ll pos = 0;
    bool cycleResets = false;

    for (int i = 0; i < n; i++) {
      cycle_time++;
      if (s[i] == 'L')
        pos--;
      else
        pos++;
      if (pos == 0) {
        cycleResets = true;
        break;
      }
    }
    if (!cycleResets) {
      cout << resets << "\n";
      continue;
    }
    ll remaining = k - time;
    ll full_cycles = remaining / cycle_time;
    resets += full_cycles;
    time += full_cycles * cycle_time;
    remaining = k - time;
    pos = 0;
    for (int i = 0; i < n && remaining > 0; i++) {
      remaining--;
      if (s[i] == 'L')
        pos--;
      else
        pos++;
      if (pos == 0) {
        resets++;
        break;
      }
    }
    cout << resets << "\n";
  }

  return 0;
}
