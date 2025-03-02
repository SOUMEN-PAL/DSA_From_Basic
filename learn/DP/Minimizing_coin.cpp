#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

#define INF INT_MAX

// Explicit Recursion Solution
int helper(const vector<int> &arr, int s) {
  if (s < 0)
    return INT_MAX;
  if (s == 0)
    return 0;
  int cnt = INT_MAX;
  for (size_t i = 0; i < arr.size(); i++) {
    int subproblem = helper(arr, s - arr[i]);
    if (subproblem != INT_MAX) {
      cnt = min(cnt, subproblem + 1);
    }
  }
  return cnt;
}

vector<int> memo;

int memo_helper(const vector<int> &arr, int s) {
  if (s < 0)
    return INT_MAX;
  if (s == 0)
    return 0;
  if (s < static_cast<int>(memo.size()) && memo[s] != -1)
    return memo[s];
  int cnt = INT_MAX;
  for (size_t i = 0; i < arr.size(); i++) {
    int subPrb = memo_helper(arr, s - arr[i]);
    if (subPrb != INT_MAX) {
      cnt = min(cnt, subPrb + 1);
    }
  }
  if (s < static_cast<int>(memo.size()))
    memo[s] = cnt;
  return cnt;
}

// DP Solution
int dp_helper(const vector<int> &arr, int s) {
  vector<int> dp(s + 1, INT_MAX);
  dp[0] = 0;
  for (int i = 1; i <= s; i++) {
    for (int coin : arr) {
      if (coin <= i && dp[i - coin] != INT_MAX) {
        dp[i] = min(dp[i], dp[i - coin] + 1);
      }
    }
  }
  return dp[s];
}

// Implicit Recursion
int rec_helper(const vector<int> &arr, int s, int i) {
  if (i >= static_cast<int>(arr.size()) || s < 0)
    return INT_MAX;
  if (s == 0)
    return 0;
  int take = rec_helper(arr, s - arr[i], i);
  if (take != INT_MAX)
    take = take + 1;
  int skip = rec_helper(arr, s, i + 1);
  return min(take, skip);
}

vector<vector<int>> imp_memo;

int implicit_memo(const vector<int> &arr, int s, int i) {
  if (i >= static_cast<int>(arr.size()) || s < 0) {
    return INT_MAX;
  }
  if (s == 0) {
    return 0;
  }

  if (static_cast<size_t>(s) < imp_memo.size() && imp_memo[s][i] != -1) {
    return imp_memo[s][i];
  }

  int take = implicit_memo(arr, s - arr[i], i);
  if (take != INT_MAX) {
    take = take + 1;
  }

  int notTake = implicit_memo(arr, s, i + 1);

  return imp_memo[s][i] = min(take, notTake);
}


int implicit_dp(const vector<int> &arr, int s) {
    int n = arr.size();
    vector<vector<int>> dp(s + 1, vector<int>(n + 1, INT_MAX));

    // Base case: sum 0 can always be formed with 0 elements
    for (int j = 0; j <= n; j++) {
        dp[0][j] = 0;
    }

    for (int i = 1; i <= s; i++) {
        for (int j = n - 1; j >= 0; j--) {
            // Not taking the current element
            dp[i][j] = dp[i][j + 1];

            // Taking the current element if possible
            if (i >= arr[j] && dp[i - arr[j]][j] != INT_MAX) {
                dp[i][j] = min(dp[i][j], dp[i - arr[j]][j] + 1);
            }
        }
    }

    return dp[s][0] == INT_MAX ? -1 : dp[s][0];
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int n, s;
  cin >> n >> s;
  vector<int> arr(n);
  for (size_t i = 0; i < arr.size(); i++) {
    cin >> arr[i];
  }

  // 1d memo char raha ha
  // memo.assign(s + 1, -1);
  // int explicit_ans = dp_helper(arr, s);
  // cout << (explicit_ans == INT_MAX ? -1 : explicit_ans) << "\n";

  // 2d memo tle
  /*
  imp_memo.assign(s + 1, vector<int>(n, -1));
  int implicit_ans = implicit_memo(arr, s, 0);
  cout << (implicit_ans == INT_MAX ? -1 : implicit_ans) << endl;
  */
  
  int ans = implicit_dp(arr , s);
  cout<<ans<<endl;
  
  return 0;
}