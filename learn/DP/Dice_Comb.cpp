#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const int MOD = 1e9 + 7;

int helper(int n){
    if(n<0) return 0;
    if(n == 0) return 1;
    int cnt = 0;
    for(int i = 1 ; i<=6 ; i++){
        cnt = (cnt + helper(n-i))%MOD;
    }
    return cnt;
}

//Momo Code
vector<int> memo(1e6+10 , -1);
int MEMO_BASED(int n){
    if(n<0) return 0;
    if(n == 0) return 1;
    
    if(memo[n] != -1){
        return memo[n];
    } 
    
    int cnt = 0;
    
    for(int i = 1 ; i<=6 ; i++){
        cnt = (cnt + MEMO_BASED(n-i))%MOD; 
    }
    
    return memo[n] = cnt;    
}

int DP_BASED(int n){
    vector<int> dp(n+1 , 0);
    dp[0] = 1; 

    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=6 ; j++){
            if(i-j>=0){
                dp[i] = (dp[i] + dp[i-j]) % MOD; 
            }
        }
    }

    return dp[n];
}


int optimizedDP(int n) {
    if (n == 0) return 1;  // Base case: There's 1 way to make sum 0 (by taking nothing)

    int sum = 1;  // dp[0] = 1 (base case)
    int current = 0;  // Stores the current value of dp[i]
    
    // Loop to compute dp[i] for i from 1 to n
    for (int i = 1; i <= n; i++) {
        current = sum;  // Current dp[i] is the sum of the last 6 values
        
        // Update the sum for the next value of dp
        sum = (sum + current) % MOD;
        
        // If the window has grown larger than 6, subtract the oldest dp value (i-6)
        if (i >= 6) {
            sum = (sum - current + MOD) % MOD;
        }
    }

    return current;  // Final result is the current dp[n]
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    int ans = DP_BASED(n);
    
    cout<<ans;
    
    
    return 0;
}