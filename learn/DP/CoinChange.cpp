#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

//Order Matters
// 1 1 2 are different for 1 2 1
int rec_code(vector<int>&coins , int sum){
    if(sum < 0){
        return 0;
    }
    if(sum == 0){
        return 1;
    }
    int ways = 0;
    for(auto i : coins){
        ways += rec_code(coins , sum - i);
    }
    return ways;
}

int dp_Order_Matters(vector<int>&coins , int sum){
    vector<int> dp(sum + 1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i<=sum ; i++){
        for(auto coin : coins){
            if(i>=coin){
                dp[i] += dp[i - coin];
            }
        }
    }
    return dp[sum];
}


//Order does not matter
// it means 1 1 2 and 1 2 1 and 2 1 1 are all same

int rec_code_order_notMatter(vector<int>&coins , int sum , int i){
    if(sum == 0){
        return 1;
    }
    
    if(sum < 0 || i >= coins.size()){
        return 0;
    }
    
    int take = rec_code_order_notMatter(coins , sum - coins[i] , i);
    int notTake = rec_code_order_notMatter(coins , sum , i+1);
    return take + notTake;
}

int dp2d(vector<int>& coins, int targetSum) {
    int n = coins.size();
    vector<vector<int>> dp(targetSum + 1, vector<int>(n, 0));
    
    // Base case: when sum is 0, there is 1 way
    for(int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }
    
    // Fill the dp table
    for(int sum = 1; sum <= targetSum; sum++) {
        for(int i = n-1; i >= 0; i--) {
            // Take the value from next index (not take)
            if(i < n-1) {
                dp[sum][i] = dp[sum][i+1];
            }
            
            // If we can take the coin, add that possibility
            if(sum >= coins[i]) {
                dp[sum][i] += dp[sum - coins[i]][i];
            }
        }
    }
    
    return dp[targetSum][0];
}


//1d dp

int dp1d(vector<int>&coins , int sum){
    vector<int> dp(sum + 1 , 0);
    
    dp[0] = 1;
    
    for(auto coin : coins){
        for(int i = coin ; i<=sum ; i++){
            if(i>=coin){
                dp[i] += dp[i-coin];
            }
        }
    }
    return dp[sum];
}




int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> coins = {1,2 ,3};
    int ans = dp1d(coins , 4);
    cout<<ans;
    return 0;
}