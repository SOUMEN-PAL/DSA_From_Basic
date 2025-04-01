#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

// Recurssive Code
int helper(string &s1 , string &s2 , int n , int m){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    
    if(s1[n-1] == s2[m-1]){
        return helper(s1 , s2 , n-1 , m-1);
    }
    else{
        return 1 + min(
            helper(s1 , s2 , n-1 , m),
            min(
                helper(s1 ,s2 , n , m-1),
                helper(s1 , s2 , n-1 , m-1)
            )
        );
    }
}

//Memo Code//
vector<vector<int>> memo;
int memo_helper(string &s1 , string &s2 , int n ,  int m){
    if(n == 0){
        return m;
    }
    if(m == 0){
        return n;
    }
    
    if(memo[n][m] != -1){
        return memo[n][m];
    }
    
    if(s1[n-1] == s2[m-1]){
        return memo[n][m] = memo_helper(s1 , s2 , n-1 , m-1);
    }
    else{
        return memo[n][m] = 1 + min(
            memo_helper(s1 , s2 , n-1 , m),
            min(
                memo_helper(s1 , s2 , n-1 , m-1),
                memo_helper(s1 , s2 , n , m-1)
            )
        );
    }
}

//DP solution
int dp_solution(string s1 , string s2){
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n+1 , vector<int>(m+1 , 0));
    
    for(int i = 0 ; i<=n ; i++){
        dp[i][0] = i;
    }
    
    for(int j = 0 ; j<=m ; j++){
        dp[0][j] = j;
    }
    
    for(int i = 1 ; i<=n ; i++){
        for(int j = 1 ; j<=m ; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1];
            }
            else{
                dp[i][j] = 1 + min(
                    dp[i-1][j-1],
                    min(
                        dp[i-1][j],
                        dp[i][j-1]
                    )
                );
            }
        }
    }
    return dp[n][m];
}

//dp solution optimised space//
class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        vector<vector<int>> dp(2, vector<int>(m + 1));

        // Base case for an empty s1
        for (int j = 0; j <= m; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= n; i++) {
            int curr = i & 1;       // current row index: 0 or 1
            int prev = 1 - curr;      // previous row index
            dp[curr][0] = i;          // base case for column 0
            
            for (int j = 1; j <= m; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[curr][j] = dp[prev][j - 1];
                else
                    dp[curr][j] = 1 + min({dp[prev][j - 1], dp[prev][j], dp[curr][j - 1]});
            }
        }
        return dp[n & 1][m];
    }
};



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1 , s2;
    cin>>s1>>s2;
    int n = s1.length();
    int m = s2.length();
    
    int ans = helper(s1 , s2 , n , m);
    cout<<ans<<endl;
    
    memo.assign(n+1 , vector<int>(m+1 , -1));
    int memoAns = memo_helper(s1 , s2 , n , m);
    cout<<memoAns<<endl;
    
    int dpAns = dp_solution(s1 , s2);
    cout<<dpAns<<endl;
    
    
    return 0;
}