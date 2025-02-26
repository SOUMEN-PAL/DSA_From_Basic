#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

//Recurssive COde

int ways(int n , int maxNum){
    if(n == 0){
        return 1;
    }
    if(n < 0 || maxNum == 0){
        //forward
        return 0;
    }
    
    return ways(n-maxNum , maxNum) + ways(n, maxNum-1);
}

// memoised Code
vector<vector<int>> memo(1e3+1 , vector<int>(1e3 , -1));
int mod = 1e9+7;
int ways_memo(int n , int mN){
    if(n == 0){
        return 1;
    }
    if(n < 0 || mN == 0){
        if( n >= 0 && mN >=0){
            return memo[n][mN] = 0;
        }
        return 0;
    }
    
    if(memo[n][mN] != -1){
        return memo[n][mN];
    }
    
    return memo[n][mN] = (ways_memo(n - mN , mN) + ways_memo(n , mN-1))%mod;
}


//Tabulation based code
//this dp is not that much optimised
vector<vector<long long>> dp(1e3+1 , vector<long long>(1e3 , 0));
ll ways_tabu(long long n , long long maxN){
    
    
    for(int j = 0 ; j<n ; j++){
        dp[0][j] = 1;
    }
    
    for(int i = 1 ; i<=n ; i++){
        dp[i][0] = 0;
    }
    
    
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<n ; j++){
            if(i >= j){
                dp[i][j] = dp[i-j][j] + dp[i][j-1];
            }
            else{
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    
    return dp[n][n-1];
}


int dp_eff(int n , int maxN){
    vector<int> dp(n+1 , 0);
    dp[0] = 1;
    
    for(int i = 1 ; i<n ; i++){
        for(int j = i ; j<=n ; j++){
            dp[j] = dp[j] + dp[j-i];
        }
    }
    return dp[n];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    cout<<dp_eff(n, n-1)<<endl;
    
    return 0;
}