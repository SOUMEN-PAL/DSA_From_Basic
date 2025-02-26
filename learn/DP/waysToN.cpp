#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int main(){
    int n;
    cin >> n;
    vector<int> dp(n+1, 0);
    dp[0] = 1; // base case: one way to partition 0
    
    // ;iterate over possible parts (1 to n-1, because n itself is not allowed)
    for(int i = 1; i <= n-1; i++){
        for(int j = i; j <= n; j++){
            dp[j] = (dp[j] + dp[j-i]) % MOD;
        }
    }
    cout << dp[n] % MOD;
    return 0;
}