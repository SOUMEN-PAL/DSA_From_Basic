#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--){
        ll n, x;
        cin >> n >> x;
        
        if(n == 1){
            cout << x << "\n";
            continue;
        }
        
        vector<ll> ans;
        for(ll i = 0; i < n; i++){
            if ((i & (~x)) == 0) { 
                ans.push_back(i);
            } else {
                break;
            }
        }
        
        if(ans.size() == n){
            ll or_val = 0;
            for(auto v : ans) {
                or_val |= v;
            }
            if(or_val != x){
                ans.back() = x;
            }
        } else {
            bool foundX = false;
            for(auto v : ans){
                if(v == x){
                    foundX = true;
                    break;
                }
            }
            if(!foundX){
                ans.push_back(x);
            }
            while(ans.size() < n)
                ans.push_back(0);
        }
        
        for(auto v : ans)
            cout << v << " ";
        cout << "\n";
    }
    
    return 0;
}
