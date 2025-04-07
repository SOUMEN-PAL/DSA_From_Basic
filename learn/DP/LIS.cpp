#include<bits/stdc++.h>
#include <iostream>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

//Recurssive solution
int recLis(vector<int> arr , int n , int last , int idx){
    if(idx == n){
        return 0;
    }
    
    int notTaken = recLis(arr , n , last , idx + 1);
    int taken = 0;
    if(last == -1 || arr[idx] > arr[last]){
        taken = 1 + recLis(arr , n , idx , idx + 1);
    }

    
    return max(taken , notTaken);
}

//DP solution
int DPSolution(vector<int> arr , int n){
    vector<vector<int>> dp(n+1 , vector<int>(n+1 , 0));
    
    for (int idx = n - 1; idx >= 0; idx--) {
        for (int last = idx - 1; last >= -1; last--) {
            int notTaken = dp[idx + 1][last + 1];
            
            int taken = 0;
            if (last == -1 || arr[idx] > arr[last])
                taken = 1 + dp[idx + 1][idx + 1];
            
            dp[idx][last + 1] = max(notTaken, taken);
        }
    }
    return dp[0][0];
}


int LIS(vector<int> &arr , int n){
    vector<int> lis(n , 1);
    lis[0] = 1;
    for(int i = 1 ; i<n ; i++){
        for(int j = 0 ; j<i ; j++){
            if(arr[i] > arr[j]){
                lis[i] = max(lis[i] , lis[j] + 1);
            }
        }
    }
    
    int maxValue = INT_MIN;
    for(int i = 0 ; i<n ; i++){
        maxValue = max(maxValue , lis[i]);
    }
    return maxValue;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i = 0 ; i<n ; i++){
        cin>>arr[i];
    }
    
    int res = LIS(arr , n);
    cout<<res<<endl;
    int recAns = recLis(arr , n , -1,  0);
    cout<<recAns<<endl;
    int dpSolution =  DPSolution(arr , n);
    cout<<dpSolution<<endl;
    return 0;
}