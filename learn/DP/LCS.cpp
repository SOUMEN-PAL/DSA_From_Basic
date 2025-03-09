#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int lcs(string s, string ss, int n, int m) {
  if (n == 0 || m == 0) {
    return 0;
  }

  if (s[n - 1] == ss[m - 1]) {
    return 1 + lcs(s, ss, n - 1, m - 1);
  }

  return max(lcs(s, ss, n - 1, m), lcs(s, ss, n, m - 1));
}

vector<vector<int>> memo;
int lcs_memo(const string &s, const string &ss, int n, int m) { // Pass strings by reference
  if (n == 0 || m == 0) {
    return 0;
  }

  if (memo[n][m] != -1) {
    return memo[n][m];
  }

  if (s[n - 1] == ss[m - 1]) {
    return memo[n][m] = 1 + lcs_memo(s, ss, n - 1, m - 1);
  }

  return memo[n][m] = max(lcs_memo(s, ss, n - 1, m), lcs_memo(s, ss, n, m - 1));
}

// dp[i][j] here i and j represents the sizes so for size 0 there cant be any
// value right;
/*
The value of dp[i][j] represents the length of the longest common subsequence
(LCS) between the first i characters of string s and the first j characters of
string ss.

*/

int lcs_dp(const string &s, const string &ss, int n, int m) {
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
  return dp[n][m];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  string s = "ABCDGH";
  string ss = "AEDFHR";

  int n = s.length();
  int m = ss.length();

  cout << lcs(s, ss, n, m) << endl;

  memo.assign(n + 1, vector<int>(m + 1, -1));
  cout << lcs_memo(s, ss, n, m) << endl;

  cout << lcs_dp(s, ss, n, m) << endl;
  return 0;
}
