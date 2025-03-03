#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;


//Brute FOrce
ll helper(vector<vector<char>> grid , int n , int i , int j){
    if(i == n-1 && j == n-1 && grid[i][j] == '.'){
        return 1;
    }
    
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j] == '*'){
       return 0; 
    }
    
    
    return (helper(grid , n , i , j+1) + helper(grid , n , i+1 , j))%MOD;  
}


//Memo based Code
vector<vector<ll>> memo;

ll memoCode(vector<vector<char>> &grid , int n , int i , int j){
    if( i == n-1 && j == n-1 && grid[i][j] == '.'){
        return 1;
    }
    
    if(i<0 || i>=n || j<0 || j>=n || grid[i][j] == '*'){
       return 0; 
    }
    
    if(memo[i][j] != -1){
        return memo[i][j];
    }
    
    return memo[i][j] = (memoCode(grid , n , i , j+1) + memoCode(grid , n , i+1 , j))%MOD;
    
}

//Dp based Code
ll dpCode(vector<vector<char>> &grid , int n){
    vector<vector<int>> dp(n , vector<int>(n , 0));
    if(grid[n-1][n-1] == '*'){
        return 0;
    }
    dp[n-1][n-1] = 1;
    
    for(int i = n-1 ; i>=0; i--){
        for(int j = n-1 ; j >= 0 ; j--){
            if(grid[i][j] == '*'){
                dp[i][j] = 0;
            }
            else{
                if(i+1 < n) dp[i][j] = (dp[i][j] + dp[i+1][j])%MOD;
                if(j+1 < n) dp[i][j] = (dp[i][j] + dp[i][j+1])%MOD;
            }
        }
    }
    
    return dp[0][0];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin>>n;
    vector<vector<char>> grid(n , vector<char>(n));
    for(int i = 0; i<n ; i++){
        for(int j = 0 ; j<n ; j++){
            cin>>grid[i][j];
        }
    }
    
    // ll ans = helper(grid , n , 0 , 0);
    // cout<<ans<<endl;
    // memo.assign(n, vector<ll>(n, -1));
    // ll memeoAns = memoCode(grid , n , 0 , 0);
    // cout<<memeoAns<<endl;
    
    ll dpAns = dpCode(grid , n);
    cout<<dpAns<<endl;
    
    return 0;
}