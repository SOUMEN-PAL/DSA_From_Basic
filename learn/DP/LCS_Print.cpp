#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

void helper(string s, string ss) {
  int n = s.length();
  int m = ss.length();

  vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i - 1] == ss[j - 1]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }

  int i = n;
  int j = m;
  string res = "";

  while (i > 0 && j > 0) {
    if (s[i - 1] == ss[j - 1]) {
      res = s[i - 1] + res; // Add character at the beginning
      // cout<<s[i-1];
      i--;
      j--;
    } else if (dp[i - 1][j] > dp[i][j - 1]) {
        // cout<<s[i-1];
      i--;
    } else {
        // cout<<s[j-1];
      j--;
    }
  }

  cout << res << endl;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "abac";
  string ss = "ab";

  helper(s, ss);

  return 0;
}
