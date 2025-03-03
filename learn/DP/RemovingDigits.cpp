#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;

int helper(ll n){
    if(n == 0) return 0;
    
    ll temp = n;
    int maxDiigit = 0;
    while(temp){
        if(maxDiigit == 9){
            break;
        }
        maxDiigit = max((ll)maxDiigit , (temp%10));
        temp = temp/10;
    }
    
    return helper(n-maxDiigit) + 1;
    
}

//dp based apraoch with optimal choice/
int dp_helper(ll n){
    vector<ll> dp(n+1 , 1e9);
    dp[0] = 0;

    for(int i = 1 ; i<=n ; i++){
        int maxDigit = 0;
        ll temp = i; 
        while(temp){
            if(maxDigit == 9){
                break;
            }
            maxDigit = max((ll)maxDigit , (temp%10));
            temp = temp/10;
        }
        
        dp[i] = dp[i-maxDigit]+1;
    }
    return dp[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    ll n;
    cin>>n;
    
    int ans = dp_helper(n);
    cout<<ans<<endl;
    
    
    
    return 0;
}