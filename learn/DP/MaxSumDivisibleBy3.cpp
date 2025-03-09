#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

// Recurssive code
int helper(vector<int> &arr , int i , int sum){
    if(i>=arr.size()){
        return sum%3 == 0?sum:0;
    }
    
    int take = helper(arr , i+1 , sum + arr[i]);
    int notTake = helper(arr , i+1 , sum);
    return max(take , notTake);
}

int max_sum_div3(vector<int> &arr , int n){
    return helper(arr , 0 , 0);
}

//More Optimised reurssive solution
int helper_rec(vector<int> &arr , int i , int r){
    if(i>=arr.size()){
        return r == 0?0:INT_MIN;
    }
    
    int take = helper_rec(arr , i+1 , (r+arr[i])%3);
    if(take != INT_MIN){
        take = take + arr[i];
    }
    
    int notTake = helper_rec(arr , i+1 , r);
    return max(take , notTake);
}

int maxSub_recAdv(vector<int> &arr , int n){
    return helper_rec(arr , 0 , 0);
}

//memo Code
vector<vector<int>> memo;
int helper_memo(const vector<int> &arr , int i , int rem){
    if(i == arr.size()){
        return rem%3 == 0 ? 0 : INT_MIN;
    }
    
    if(memo[i][rem] != -1){
        return memo[i][rem];
    }
    
    //take
    int take = helper_memo(arr , i+1 , (rem + arr[i])%3);
    if(take != INT_MIN){
        take = take + arr[i];
    }
    //not take
    int notTake = helper_memo(arr , i+1 , rem);
    return memo[i][rem] =  max(take , notTake);
}

int maxSub_memo(vector<int> arr , int n){
    return helper_memo(arr , 0 , 0);
}

//DP code
int divSumMod3(const vector<int> &arr , int n){
    vector<vector<int>> dp(n+1 , vector<int>(3 , INT_MIN));
    dp[n][0] = 0;
    
    for(int i = n-1 ; i>= 0 ; i--){
        for(int r = 0 ; r<=2 ; r++){
            //take
            int take = dp[i+1][(r + arr[i])%3];
            if(take != INT_MIN){
                take = take + arr[i];
            }
            //not take
            int notTake = dp[i+1][r];
            
            dp[i][r] = max(take , notTake);
        }
    }
    return dp[0][0];
}


///Most eff approach
int eff_approach(vector<int> arr , int n){
    int sum = 0;
    int min1_first = 1e4+1 , min1_second = 1e4+1 , min2_first = 1e4 + 1 , min2_second = 1e4+1;
    for(auto i : arr){
        sum += i;
        if(i % 3 == 1){
            if(i < min1_first){
                min1_second = min1_first;
                min1_first = i;
            }
            else if(i < min1_second){
                min1_second = i;
            }
        }
        else if(i % 3 == 2){
            if(i < min2_first){
                min2_second = min2_first;
                min2_first = i;
            }
            else if(min2_second > i){
                min2_second = i;
            }
        }
    }
    
    if(sum%3 == 0){
        return sum;
    }
    
    if(sum % 3 == 1){
        return max(sum - min1_first , sum - min2_first - min2_second);
    }
    
    return max(sum - min2_first , sum - min1_first - min1_second);
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
    
    
    int ans = max_sum_div3(arr , n);
    cout<<ans<<endl;
    ans = maxSub_recAdv(arr , n);
    cout<<ans<<endl;
    
    memo.assign(n , vector<int>(3 , -1));
    ans = maxSub_memo(arr , n);
    cout<<ans<<endl;
    
    ans = divSumMod3(arr , n);
    cout<<ans<<endl;
    
    ans = eff_approach(arr , n);
    cout<<ans<<endl;
    
    return 0;
}