#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

// Optimized combinatorial formula approach
ll nCr(int n, int r) {
    if (r > n) return 0;
    if (r == 0 || r == n) return 1;
    
    if (r > n - r) r = n - r; // Use symmetry C(n, r) = C(n, n-r)
    
    ll sum = 1;
    for (int i = 1; i <= r; i++) {
        sum = sum * (n - r + i) / i;
    }
    return sum;
}

// DP-based approach
ll nCr_dp(int n, int k) {
    vector<vector<ll>> dp(n+1, vector<ll>(k+1, 0));
    
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, k); j++) {
            if (j == 0 || j == i) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
            }
        }
    }
    return dp[n][k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    
    cout << nCr(n, k) << endl;
    cout << nCr_dp(n, k) << endl;
    
    return 0;
}
