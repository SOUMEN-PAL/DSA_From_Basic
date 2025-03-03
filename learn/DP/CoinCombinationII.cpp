#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;

//best for tracking I mean the recurssion flow is best for printting and DP is implemented is from that/
ll solution(vector<ll> &arr , ll s){
    ll n = arr.size();
    vector<vector<ll>> dp(s+1 , vector<ll>(n+1 , 0));
    
    for(ll j = 0 ; j<n ; j++){
        dp[0][j] = 1;
    }
    
    for(ll i = 1 ; i<=s ; i++){
        for(ll j = n-1 ; j>=0 ; j--){
            ll notTake = dp[i][j+1];
            ll take = 0;
            if(i >= arr[j] && dp[i-arr[j]][j] != 0){
                take = dp[i-arr[j]][j];
            }
            
            dp[i][j] = (take + notTake)%MOD;
        }
    }
    return dp[s][0];
}


//best for counting//

ll helper(vector<ll> &arr , int s){
    vector<ll> dp(s+1 , 0);
    dp[0] = 1;
    
    for(auto coins : arr){
        for(ll i = coins ; i<=s ; i++){
            dp[i] = (dp[i] + dp[i-coins])%MOD;
        }
    }
    return dp[s];
}



int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , s;
    cin>>n>>s;
    vector<ll> coins(n);
    for(int i = 0 ; i<n ; i++){
        cin>>coins[i];
    }
    ll ans = helper(coins , s);
    cout<<ans<<endl;
    
    return 0;
}