#include<bits/stdc++.h>
using namespace std;

//0.1 knapsack bottom up
int knapsack1(int wt[], int val[], int W, int n){
    int dp[n+1][W+1];
    for(int i = 0; i <= n; i++){
        for(int w = 0; w <= W; w++){
            if(i == 0 || w == 0){
                dp[i][w] = 0;
            }else if(wt[i-1] <= w){
                dp[i][w] = max(val[i-1] + dp[i-1][w - wt[i-1]], dp[i-1][w]);
            }else{
                dp[i][w] = dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}

//0.1 knapsack top down
int knapsack2(int wt[], int val[], int W, int n){
    if(n == 0 || W == 0){
        return 0;
    }
    if(wt[n-1] <= W){
        return max(val[n-1] + knapsack2(wt, val, W - wt[n-1], n-1), knapsack2(wt, val, W, n-1));
    }else{
        return knapsack2(wt, val, W, n-1);
    }
}


//0.1 knapsack top down with memoization
int knapsack3(int wt[], int val[], int W, int n, vector<vector<int>> &dp){
    if(n == 0 || W == 0){
        return 0;
    }
    if(dp[n][W] != -1){
        return dp[n][W];
    }
    if(wt[n-1] <= W){
        dp[n][W] = max(val[n-1] + knapsack3(wt, val, W - wt[n-1], n-1, dp), knapsack3(wt, val, W, n-1, dp));
    }else{
        dp[n][W] = knapsack3(wt, val, W, n-1, dp);
    }
    return dp[n][W];
}



int main(){
    
    int wt[] = {1, 3, 4, 5};
    int val[] = {1, 4, 5, 7};
    int W = 7;
    int n = sizeof(wt)/sizeof(wt[0]);
    cout<<knapsack1(wt, val, W, n)<<endl;

    vector<vector<int>> dp(n+1, vector<int>(W+1, -1));
    cout<<knapsack3(wt, val, W, n, dp)<<endl;



    
    return 0;
}