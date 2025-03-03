#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9+7;

ll helper(vector<ll> &coins , int x){
    int n = coins.size();
    vector<ll> dp(x+1 , 0);
    dp[0] = 1;
    for(int i = 1 ; i<=x ; i++){
        for(auto coin : coins){
            if(coin <= i && dp[i - coin] != 0){
                dp[i] = (dp[i] + dp[i - coin])%MOD;
            }
        }
    }
    return dp[x];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n , x;
    cin>>n>>x;
    
    vector<ll> coins(n);
    for(int i = 0 ;i<n ; i++){
        cin>>coins[i];
    }
    
    
    ll ans=helper(coins , x);
    cout<<ans<<endl;
    
    return 0;
}