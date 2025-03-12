#include <algorithm>
#include<bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;


//Memo code is giving TLE//
vector<int> memo;
int rec(int n, vector<int> &arr, int idx) {
    // Base case: reached the last index
    if(idx >= n-1) {
        return 0;
    }

    // If current position has 0 jumps possible
    if(arr[idx] == 0) {
        return INT_MAX;
    }


    if(memo[idx] != -1){
        return memo[idx];
    }


    int ans = INT_MAX;

    // Try all possible jumps from current position
    for(int s = 1; s <= arr[idx]; s++) {
        if(idx + s < n) {
            int subProblem = rec(n, arr, idx + s);
            if(subProblem != INT_MAX) {
                ans = min(ans, subProblem + 1);
            }
        }
    }

    return memo[idx] =  ans;
}


// DP code //
int dp_approach(vector<int> &arr, int n) {
    vector<int> dp(n, INT_MAX);
    dp[n-1] = 0;  
    
    for(int i = n-2; i >= 0; i--) {
        if(arr[i] > 0) {  
            for(int j = 1; j <= arr[i] && i + j < n; j++) {
                if(dp[i+j] != INT_MAX) {  
                    dp[i] = min(dp[i], 1 + dp[i+j]);  
                }
            }
        }
    }
    
    return dp[0] == INT_MAX ? -1 : dp[0];  
}

// Greedy Approach //
int greedyApproach(vector<int> &arr , int n){
    int jumps = 0;
    int l = 0;
    int r = 0;
    
    while(r < n-1){
        
        int farthest = 0;
        for(int i = l ; i<=r ; i++){
            farthest = max(arr[i] + i , farthest);
        }
        
        l = r+1;
        r = farthest;
        jumps = jumps + 1;
    }
    return jumps;
}



int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    memo.assign(n , -1);
    int ans = rec(n, arr, 0);
    cout << (ans == INT_MAX ? -1 : ans)<<endl;  // Print -1 if no path is possible
    
    int sol = dp_approach(arr , n);
    cout<<sol<<endl;
    
    int greedySolution = greedyApproach(arr , n);
    cout<<greedySolution<<endl;
    
    return 0;
}
